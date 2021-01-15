#include "client.hpp"

namespace mapper
{
    TcpClient::TcpClient(boost::asio::io_service &service,
                         std::string ip,
                         int port)
        : io_service_(service),
          ip_(boost::asio::ip::address::from_string(ip)),
          address_(ip_, port),
          session_ptr_(nullptr)
    {
    }

    TcpClient::~TcpClient()
    {
    }

    void TcpClient::setMessageCallback(std::function<void(TcpSession &s, std::string &msg)> func)
    {
        message_callback_ = func;
    }

    void TcpClient::setOnConnectCallback(std::function<void(TcpSession &s)> func)
    {
        connect_callback_ = func;
    }

    void TcpClient::setCodec(std::shared_ptr<BaseCodec> codec_ptr)
    {
        codec_ptr_ = codec_ptr;
    }

    void TcpClient::start()
    {
        connect();
    }

    void TcpClient::connect()
    {
        boost::asio::ip::tcp::socket sock(io_service_);
        sock.async_connect(address_,
                           std::bind(&TcpClient::connectCallback,
                                     this,
                                     std::placeholders::_1,
                                     sock));
    }

    void TcpClient::connectCallback(boost::system::error_code ec, boost::asio::ip::tcp::socket &socket)
    {
        if (ec)
        {
            return;
        }
        session_ptr_ = std::make_shared<TcpSession>(socket);
        connect_callback_(*session_ptr_);
        session_ptr_->start();
    }
} // namespace mapper