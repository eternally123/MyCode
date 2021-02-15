/**
 * 普通成员函数调用方法
 **/
#include <iostream>
using namespace std;

int main()
{
}

/**
 * 对普通成员函数的调用和全局成员函数调用等价。效率没有更低。
 * 同时nm命令可以看到，成员函数的地址也是编译期间确定好的。
 **/