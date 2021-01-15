#include "server.hpp"

namespace mapper
{
    TcpServer::TcpServer(boost::asio::io_service &service,
                         std::string ip,
                         int port)
        : io_service_(service),
          ip_(boost::asio::ip::address::from_string(ip)),
          address_(ip_, port),
          acceptor_(service, address_),
          message_callback_(nullptr),
          codec_ptr_(std::make_shared<BaseCodec>()),
          started_(0)
    {
    }

    TcpServer::~TcpServer()
    {
    }

    void TcpServer::setMessageCallback(std::function<void(TcpSession &s, std::string &msg)> func)
    {
        message_callback_ = func;
    }

    void TcpServer::setCodec(std::shared_ptr<BaseCodec> codec_ptr)
    {
        codec_ptr_ = codec_ptr;
    }

    void TcpServer::start()
    {
        if (0 == started_)
        {
            started_ = 1;
            accept();
        }
        return;
    }

    void TcpServer::accept()
    {
        acceptor_.async_accept(std::bind(&TcpServer::acceptCallback,
                                         this,
                                         std::placeholders::_1,
                                         std::placeholders::_2));
    }

    void TcpServer::acceptCallback(boost::system::error_code ec,
                                   boost::asio::ip::tcp::socket sock)
    {
        std::shared_ptr<TcpSession> session_ptr = std::make_shared<TcpSession>(std::move(sock));
        session_vec_.push_back(session_ptr);
        session_ptr->start();
        accept();
    }
} // namespace mapper