#include <asio.hpp>
#include <memory>
#include <functional>
#include <iostream>

const int BUFFER_SIZE = 1024;

class TcpServer
{
public:
    TcpServer()
        : io_(),
          acceptor_(io_, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), 10000))
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

    void read(std::shared_ptr<asio::ip::tcp::socket> sockptr)
    {
        sockptr->async_read_some(asio::buffer(data_, 10),
                                 std::bind(&TcpServer::readHandle, this, std::placeholders::_1, std::placeholders::_2, sockptr));
        // sockptr->async_read_some(asio::buffer(data_, 10),
                                //  std::bind(&TcpServer::readHandle, this, std::placeholders::_1, std::placeholders::_2, sockptr));
   
    }

    void acceptHandle(asio::error_code err, std::shared_ptr<asio::ip::tcp::socket> sockptr)
    {
        if (err)
            return;

        std::cout << "accept one connection:" << sockptr->remote_endpoint().address()
                  << ":" << sockptr->remote_endpoint().port() << std::endl;
        read(sockptr);
        accept();
    };

    void readHandle(asio::error_code err, std::size_t num, std::shared_ptr<asio::ip::tcp::socket> sockptr)
    {
        if (err)
            return;
        std::cout << "read " << num << " bytes data from connection:"
                  << sockptr->remote_endpoint().address() << ":" << sockptr->remote_endpoint().port()
                  << ".\ncontents:";
        for (int i = 0; i < num; i++)
            std::cout << data_[i];
        std::cout << std::endl;

        read(sockptr);
    }

private:
    asio::io_service io_;
    asio::ip::tcp::acceptor acceptor_;
    char data_[BUFFER_SIZE];
};

int main()
{
    TcpServer server;
    server.run();
}