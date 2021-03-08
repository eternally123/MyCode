#pragma once

extern "C"
{
#include "libavcodec/avcodec.h"
#include "libswscale/swscale.h"
#include "libavformat/avformat.h"
#include "libavutil/avutil.h"
#include "libavdevice/avdevice.h"
}
#include <opencv2/opencv.hpp>
class FfmpegDecoder 
{
public:
    /**
     * @brief 调用此构造函数后需要调用start()开始解码
     * 
     */
    FfmpegDecoder();

    /**
     * @brief Construct a RAII Ffmpeg Decoder object
     * 
     * @param url 
     * @param codepar 
     */
    FfmpegDecoder(const char* url, AVCodecParameters** codepar)
    {
        FfmpegDecoder();
        onStart(url, codepar);
    }

    ~FfmpegDecoder();

    /**
     * @brief 
     * 
     * @param url 
     * @param codecpar 
     * @return true 
     * @return false 
     */
    virtual bool start(const char* url, AVCodecParameters** codecpar)
    {
        onStart(url, codecpar);
    }
    
    virtual void stop()
    {
        stopped_ = true;
    }

    /**
     * @brief 获取图像帧
     * 
     * @param img 图像数据
     * @param packet 申请的内存空间地址，用于存放中间数据
     * @return true 成功
     * @return false 失败
     */
    virtual bool getImage(cv::Mat& img, AVPacket* packet);

    int  get_fps()
    {
        return fps_;
    }
private:
    void release();

    bool onStart(const char* url, AVCodecParameters** codecpar);

private:
  
    AVFormatContext *format_context_ = nullptr; //一个媒体文件的构成和基本信息
    int video_stream_index_;
    AVCodecContext *codec_context_ = nullptr;   //除了包含解码器之外还包含了音视频流的其他信息，例如分辨率、比特率等
    AVFrame* yuv_frame_ = nullptr;  //解码后的原始数据，此为解码器输出
    AVPacket packet_;   //压缩的帧
    SwsContext* y2r_sws_context_ = nullptr; //处理图片像素数据类库

    int rgb_line_size_;

    volatile bool stopped_;
    uint32_t last_alive_tick_;

    int fps_ = 0;
};

