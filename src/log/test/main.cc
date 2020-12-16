#include "log.hh"
#include <string>

int main()
{
    std::string str = "my log";
    INFO_LOG("hello world %s ", str.c_str());
}