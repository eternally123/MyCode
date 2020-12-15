#include "log.hh"

#include <string>

#define DEBUG 1

int main()
{
    int i = 10;
    std::string str = "my log class";
    INFO_LOG("helloworld %s \n", str.c_str());
}