#include "ffmpeg_decoder.hh"
#include "get_tick_count.hh"

//#include <regex>
//#include <glog/logging.h>

FfmpegDecoder::FfmpegDecoder()
{
    static bool is_reg_flag = false;
    if(!is_reg_flag)
    {
#if LIBAVCODEC_VERSION_MAJOR < 58
        av_register_all();
#endif
        avformat_network_init();
        is_reg_flag = true;
    }

    format_context_ = avformat_alloc_context();

    yuv_frame_ = av_frame_alloc();
}

FfmpegDecoder::~FfmpegDecoder()
{
    release();
}


bool FfmpegDecoder::onStart(const char* url, AVCodecParameters** codec)
{
    stopped_ = false;

    last_alive_tick_ = AIVG::GetTickCount();
    format_context_->interrupt_callback.callback = [](void* decoder) -> int {
        return ((FfmpegDecoder*)decoder)->stopped_ || (int)(AIVG::GetTickCount() - ((FfmpegDecoder*)decoder)->last_alive_tick_) > 6000;
    };  // 由于后续打开视频流是阻塞的，因此这个回调是用来控制时长
    format_context_->interrupt_callback.opaque = this;

    AVDictionary* options = nullptr;
    av_dict_set(&options, "rtsp_transport", "tcp", 0);
    av_dict_set(&options, "stimeout", "3000000", 0);
    av_dict_set(&options, "bufsize", "2097151", 0);
    av_dict_set(&options, "pkt_size", "2097151", 0);

    int ret = avformat_open_input(&format_context_, url, NULL, &options);
    if(ret < 0)
    {
        return false;
    }

    ret = avformat_find_stream_info(format_context_, nullptr);
    if(ret < 0)
    {
        return false;
    }

    video_stream_index_ = -1;

    video_stream_index_ = av_find_best_stream(format_context_, AVMEDIA_TYPE_VIDEO, -1, -1, NULL, 0);
    if(video_stream_index_ < 0)
    {
        return false;
    }

    if(format_context_->streams[video_stream_index_]->avg_frame_rate.den)
    {
        fps_ = format_context_->streams[video_stream_index_]->avg_frame_rate.num / format_context_->streams[video_stream_index_]->avg_frame_rate.den;
    }

    AVCodecParameters* codepar;
    codepar = format_context_->streams[video_stream_index_]->codecpar;
    *codec = codepar;

    do
    {
        AVCodec *codec_ptr;
        if(AV_CODEC_ID_H264 == codepar->codec_id)
        {
            codec_ptr = avcodec_find_decoder_by_name("h264_cuvid");
        }
        else    //获得cuvid解码器失败
        {
            codec_ptr = avcodec_find_decoder(codepar->codec_id);
        }

        codec_context_ = avcodec_alloc_context3(codec_ptr);
        if(!codec_context_)
        {
            break;
        }

        ret = avcodec_parameters_to_context(codec_context_, codepar);
        if(ret < 0)
        {
            break;
        }

        ret = avcodec_open2(codec_context_, codec_ptr, nullptr);
        if(ret < 0)
        {
            avcodec_free_context(&codec_context_);
            break;
        }

    } while(0);

    return true;

}

bool FfmpegDecoder::getImage(cv::Mat& img, AVPacket* packet)
{
    for(;;)
    {
        last_alive_tick_ = AIVG::GetTickCount();
        
        int ret = av_read_frame(format_context_, &packet_);
        if(AVERROR(EAGAIN) == ret)
        {
            continue;
        }
        else if(ret < 0)
        {
            return false;
        }

        if(packet_.stream_index != video_stream_index_)
        {
            av_packet_unref(&packet_);
            continue;
        }

        ret = avcodec_send_packet(codec_context_, &packet_);
        if(-11 == ret)
        {
            av_packet_unref(&packet_);
            return false;
        }

        ret = avcodec_receive_frame(codec_context_, yuv_frame_);
        if(ret < 0)
        {
            av_packet_unref(&packet_);
            return false;
        }

        if(!y2r_sws_context_)
        {
            y2r_sws_context_ = sws_getContext(codec_context_->width, 
                                            codec_context_->height, 
                                            codec_context_->pix_fmt, 
                                            codec_context_->width, 
                                            codec_context_->height, 
                                            AV_PIX_FMT_BGR24, 
                                            /*SWS_BICUBIC*/ SWS_BILINEAR, 
                                            NULL, NULL, NULL);
            if(!y2r_sws_context_)
            {
                av_packet_unref(&packet_);
                return false;
            }
            rgb_line_size_ = codec_context_->width * 3;
        }

        if(!img.data)
        {
            img.create(codec_context_->height, codec_context_->width, CV_8UC3);
        }

        ret = sws_scale(y2r_sws_context_, yuv_frame_->data, yuv_frame_->linesize, 0, codec_context_->height, &img.data, &rgb_line_size_);
        if(ret <= 0)
        {
            av_packet_unref(&packet_);
            av_frame_unref(yuv_frame_);
            return false;
        }

        av_frame_unref(yuv_frame_);
        av_packet_move_ref(packet, &packet_);

        break;
    }

    return true;
}


void FfmpegDecoder::release()
{
    if(yuv_frame_)
    {
        av_frame_free(&yuv_frame_);
        yuv_frame_ = nullptr;
    }
    if(codec_context_)
    {
        avcodec_close(codec_context_);
        avcodec_free_context(&codec_context_);
        codec_context_ = nullptr;
    }
    if(format_context_)
    {
        avformat_close_input(&format_context_);
        format_context_ = nullptr;
    }
    if(y2r_sws_context_)
    {
        sws_freeContext(y2r_sws_context_);
        y2r_sws_context_ = nullptr;
    }
}

