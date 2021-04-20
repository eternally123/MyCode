#include <cstdlib>
#include <iostream>
#include <memory>
#include <utility>
#include <asio.hpp>
#include <asio/steady_timer.hpp>
#include <asio/system_timer.hpp>
#include <chrono>
#include <functional>

void print(const std::error_code &ec)
{
    std::cout << "timer" << std::endl;
}

int main(int argc, char *argv[])
{
    asio::io_service ios;
    asio::steady_timer timer(ios);
    asio::system_timer t(ios);
    timer.expires_from_now(std::chrono::seconds(2));
    timer.async_wait(std::bind(&print, std::placeholders::_1));
    t.expires_from_now(std::chrono::seconds(3));
    t.async_wait(std::bind(&print, std::placeholders::_1));

    ios.run();
}