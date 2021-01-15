#pragma once

#include "session.hpp"
#include "codec.hpp"

#include <boost/asio.hpp>
#include <vector>

namespace mapper
{
    class TcpServer
    {
    public:
        TcpServer(boost::asio::io_service &service,
               std::string ip,
               int port);
        virtual ~TcpServer();
        void setMessageCallback(std::function<void(TcpSession &s, std::string &msg)> func);
        void setCodec(std::shared_ptr<BaseCodec> codec_ptr);
        void start();

    private:
        void accept();
        void acceptCallback(boost::system::error_code ec,
                            boost::asio::ip::tcp::socket socket);

    private:
        // io_service
        boost::asio::io_service &io_service_;

        // 地址信息
        boost::asio::ip::address ip_;
        boost::asio::ip::tcp::endpoint address_;
        boost::asio::ip::tcp::acceptor acceptor_;

        // 消息编解码器与消息回调
        std::function<void(TcpSession &s, std::string &msg)> message_callback_;
        std::shared_ptr<BaseCodec> codec_ptr_;

        // 连接信息
        std::vector<std::shared_ptr<TcpSession>> session_vec_;

        //
        int started_;
    };
} // namespace mapper