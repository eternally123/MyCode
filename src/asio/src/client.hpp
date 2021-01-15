#pragma once

#include "session.hpp"
#include "codec.hpp"

#include <boost/asio.hpp>

namespace mapper
{
    class TcpClient
    {
    public:
        TcpClient(boost::asio::io_service &service,
                  std::string ip,
                  int port);
        virtual ~TcpClient();

        void start();
        void connect();

        void setMessageCallback(std::function<void(TcpSession &s, std::string &msg)> func);
        void setOnConnectCallback(std::function<void(TcpSession &s)> func);
        void setCodec(std::shared_ptr<BaseCodec> codec_ptr);

    private:
        void connectCallback(boost::system::error_code ec, boost::asio::ip::tcp::socket &socket);

    private:
        boost::asio::io_service &io_service_;

        boost::asio::ip::address ip_;
        boost::asio::ip::tcp::endpoint address_;

        std::function<void(TcpSession &s, std::string &msg)> message_callback_;
        std::function<void(TcpSession &s)> connect_callback_;
        std::shared_ptr<BaseCodec> codec_ptr_;

        std::shared_ptr<TcpSession> session_ptr_;
    };
} // namespace mapper
