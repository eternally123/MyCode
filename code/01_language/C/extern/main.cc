#include "h1.hh"
#include <iostream>
using namespace std;

// extern static int m = 10; more than one storage class may not be specified 冲突
int main()
{
    cout << "main()\tvalue:" << num << " address:" << &num << endl;
    print();
    num = -1;
    print();
    cout << "main()\tvalue:" << num << " address:" << &num << endl;
}

/**
 * extern在.h中声明变量，然后在.c中定义变量
 **/