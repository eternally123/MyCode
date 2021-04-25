#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <iostream>
#include <string>

using namespace boost::asio;

void PrintSomething(const std::string &msg)
{
    std::cout << msg << '\n';
}

void PrintHello()
{
    std::cout << "Hello\n";
}

int main()
{
    io_service service;

    service.post(PrintHello);
    service.post(boost::bind(PrintSomething, "whoami"));

    //service.run_one();
    service.run();

    return 0;
}