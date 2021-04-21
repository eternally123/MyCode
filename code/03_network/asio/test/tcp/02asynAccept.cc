#include <asio.hpp>
#include <memory>
#include <functional>
#include <iostream>

class TcpServer
{
public:
    TcpServer()
        : acceptor_(io_, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), 10000))
    {
        accept();
    }
    void run()
    {
        io_.run();
    }
    void accept()
    {
        std::shared_ptr<asio::ip::tcp::socket> sockptr = std::make_shared<asio::ip::tcp::socket>(io_);
        acceptor_.async_accept(*sockptr, std::bind(&TcpServer::acceptHandle, this, std::placeholders::_1, sockptr));
    }
    void acceptHandle(asio::error_code err, std::shared_ptr<asio::ip::tcp::socket> sockptr)
    {
        if (err)
        {
            std::cout << "error accept" << std::endl;
            return;
        }
        std::cout << "accept one connection:" << sockptr->remote_endpoint().address()
                  << ":" << sockptr->remote_endpoint().port() << std::endl;
        accept();
    };

private:
    asio::io_service io_;
    asio::ip::tcp::acceptor acceptor_;
};

int main()
{
    TcpServer server;
    server.run();
}