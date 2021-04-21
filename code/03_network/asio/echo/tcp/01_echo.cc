#include <cstdlib>
#include <iostream>
#include <memory>
#include <utility>
#include <boost/asio.hpp>
#include <vector>

using boost::asio::ip::tcp;

class session
    : public std::enable_shared_from_this<session>
{
public:
    session(tcp::socket socket)
        : socket_(std::move(socket))
    {
    }

    void start()
    {
        do_read();
    }

private:
    void do_read()
    {
        socket_.async_read_some(boost::asio::buffer(data_, max_length),
                                std::bind(&session::readHandle, shared_from_this(), std::placeholders::_1, std::placeholders::_2));
    }

    void do_write(std::size_t length)
    {
        boost::asio::async_write(socket_, boost::asio::buffer(data_, length),
                                 std::bind(&session::writeHandle, shared_from_this(), std::placeholders::_1, std::placeholders::_2));
    }

    void writeHandle(boost::system::error_code ec, std::size_t length)
    {
        std::cout << "error_code:" << ec << "\nlength:" << length << "\n";
        if (!ec)
        {
            do_read();
        }
    }

    void readHandle(boost::system::error_code ec, std::size_t length)
    {
        std::cout << "error_code:" << ec << "\nlength:" << length << "\n";
        if (!ec)
        {
            do_write(length);
        }
    }

private:
    enum
    {
        max_length = 1024
    };
    tcp::socket socket_;
    char data_[max_length];
};

class server
{
public:
    server(boost::asio::io_context &io_context, short port)
        : acceptor_(io_context, tcp::endpoint(tcp::v4(), port))
    {
        do_accept();
    }

private:
    void do_accept()
    {
        acceptor_.async_accept(std::bind(&server::acceptHandle, this, std::placeholders::_1, std::placeholders::_2));
    }

    void acceptHandle(boost::system::error_code ec, tcp::socket socket)
    {
        if (!ec)
        {
            auto s = std::make_shared<session>(std::move(socket));
            s->start();
            sessions_.push_back(s);
        }

        do_accept();
    }

private:
    tcp::acceptor acceptor_;
    std::vector<std::shared_ptr<session>> sessions_;
};

int main(int argc, char *argv[])
{
    try
    {
        if (argc != 2)
        {
            std::cerr << "Usage: async_tcp_echo_server <port>\n";
            return 1;
        }
        boost::asio::io_context io_context;
        server s(io_context, std::atoi(argv[1]));
        io_context.run();
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }
    return 0;
}