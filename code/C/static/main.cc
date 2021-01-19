#include "h1.hh"
#include <iostream>
using namespace std;

int main()
{
    cout << "main()\tvalue:" << num << " address:" << &num << endl;
    print();
    num = -1;
    print();
}

/**
 * static变量有内部链接属性，在main.cc与h1.cc中是两个变量
 **/