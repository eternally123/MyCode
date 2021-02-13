#include <iostream>
using namespace std;

class MYACLS
{
public:
    int m_i;
    int m_j;
    virtual void myvirfunc() {}
    MYACLS() { int abc = 1; }
    ~MYACLS() { int def = 0; }
};

int main()
{
    MYACLS aaa;
}

/**
 * 单个带虚函数的数据成员分布
 * 
 * 通过反汇编查看可以得知：
 * ①编译的时候，编译器会产生虚函数表。
 * 同时编译器在类的构造析构析构中加入代码，为vptr赋值。
 * ②对象模型中，vptr在最前面，后面依次是声明的变量。
 **/