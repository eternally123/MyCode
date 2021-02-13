#include <iostream>
#include <time.h>
#include <cstdio>
using namespace std;

class Base
{
public:
    virtual void mybvirfunc() {}
    int m_bi;

public:
    Base()
    {
        printf("Base::Base()构造函数的this指针是：%p!\n", this);
    }
};

class MYACLS : public Base
{
public:
    int m_i;
    int m_j;

    virtual void myvirfunc()
    {
    }
    MYACLS() //构造函数
    {
        printf("MYACLS::MYACLS()构造函数的this指针是：%p!\n", this);
    }
    ~MYACLS() //析构函数
    {
    }
};

int main()
{
    MYACLS aaa;
    cout << sizeof(MYACLS) << endl;
    printf("MYACLS::m_bi = %d\n", &MYACLS::m_bi);
    printf("MYACLS::m_i = %d\n", &MYACLS::m_i);
    printf("MYACLS::m_j = %d\n", &MYACLS::m_j);

    return 0;
}
// 运行结果
// Base::Base()构造函数的this指针是：0x7ffe5efab2e0!
// MYACLS::MYACLS()构造函数的this指针是：0x7ffe5efab2e0!
// 24
// MYACLS::m_bi = 8
// MYACLS::m_i = 12
// MYACLS::m_j = 16

/**
 * 父类子类都有虚函数
 * 分析，和4.6类似，内存布局
 **/