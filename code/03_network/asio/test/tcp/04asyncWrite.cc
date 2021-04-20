#include <asio.hpp>
#include <memory>
#include <functional>
#include <iostream>

const int BUFFER_SIZE = 10;

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

    void write(std::shared_ptr<asio::ip::tcp::socket> sockptr)
    {
        // char data_[BUFFER_SIZE] = {'a', 'c'}; // write应该是会拷贝数据到asio内部
        sockptr->async_write_some(asio::buffer("helloworld", 11),
                                  std::bind(&TcpServer::writeHandle, this, std::placeholders::_1, std::placeholders::_2, sockptr));
    }

    void acceptHandle(asio::error_code err, std::shared_ptr<asio::ip::tcp::socket> sockptr)
    {
        if (err)
            return;

        std::cout << "accept one connection:" << sockptr->remote_endpoint().address()
                  << ":" << sockptr->remote_endpoint().port() << std::endl;
        write(sockptr);
        accept();
    }

    void writeHandle(asio::error_code err, std::size_t num, std::shared_ptr<asio::ip::tcp::socket> sockptr)
    {
        if (err)
            return;
        std::cout << "write " << num << " bytes data to client:"
                  << sockptr->remote_endpoint().address() << ":" << sockptr->remote_endpoint().port()
                  << ".\ncontents:";
        std::cout << std::endl;
    }

private:
    asio::io_service io_;
    asio::ip::tcp::acceptor acceptor_;
};

int main()
{
    TcpServer server;
    server.run();
}