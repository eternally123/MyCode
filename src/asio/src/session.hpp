#pragma once

#include "buffer.hpp"
#include "codec.hpp"

#include <memory>
#include <iostream>
#include <vector>
#include <string>

#include <boost/asio.hpp>
namespace mapper
{
    class TcpSession
    {
    public:
        TcpSession(boost::asio::ip::tcp::socket socket);
        ~TcpSession();
        void start();
        void write(std::string &msg);
        void setonMessageCallback(std::function<void(TcpSession &s, std::string &msg)> func);

    private:
        // 将数据写入、读出os socket buffer
        void doRead();
        void doWrite();
        // 从socket读写数据的回调
        void readCallback(boost::system::error_code ec,
                          std::size_t length);
        void writeCallback(boost::system::error_code ec,
                           std::size_t length);

        boost::asio::ip::tcp::socket socket_;
        Buffer read_buffer_;
        Buffer write_buffer_;
        std::vector<char> temporary_read_buffer_;
        std::vector<char> temporary_write_buffer_;

        // 收到消息的回调
        std::function<void(TcpSession &s, std::string &msg)> message_callback_ = nullptr;
        // 消息编解码器
        std::shared_ptr<BaseCodec> codec_ptr_;
    };
} // namespace mapper
