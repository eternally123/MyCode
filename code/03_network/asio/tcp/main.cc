#include <cstdlib>
#include <iostream>
#include <memory>
#include <utility>
#include <asio.hpp>
#include <asio/steady_timer.hpp>
#include <asio/system_timer.hpp>
#include <chrono>
#include <functional>

int main(int argc, char *argv[])
{
    int *p = new int;
    std::cout << *p << std::endl;
    int *q = new (p) int(10);
    std::cout << *q << std::endl;
    std::cout << *(int *)p << std::endl;
    delete q;
    // delete p; //error double delete
}