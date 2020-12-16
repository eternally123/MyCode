#include "log.hh"

#include <string>

#define DEBUG 1

int main()
{
    int i = 10;
    std::string str = "my log class";
    INFO_LOG("helloworld %s", str.c_str());
    ERROR_LOG("helloworld %s", str.c_str());
    FATAL_LOG("helloworld %s", str.c_str());
}