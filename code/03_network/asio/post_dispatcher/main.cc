#include <boost/asio.hpp>
#include <functional>
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
    io_context context;

    context.post(PrintHello);
    context.post(std::bind(PrintSomething, "who am i"));
    std::cout << "hello world begin\n";

    //context.run_one();
    context.run();

    return 0;
}