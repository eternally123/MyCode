#include "main.hh"

int main()
{
    Derived d;
    d.print();
}

/**
 * g++ -O -Winline  main.cc 为什么不报警告信息？？？
 **/