#include <asio.hpp>

int main()
{
    asio::io_service io;
    asio::ip::tcp::acceptor listen_agent(io, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), 10000));
    while (1)
    {
        asio::ip::tcp::socket sock(io);
        listen_agent.accept(sock);
        sock.send(asio::buffer("hello world"));
    }
}