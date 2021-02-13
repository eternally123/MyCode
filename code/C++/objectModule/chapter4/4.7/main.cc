#include <iostream>
#include <time.h>
#include <cstdio>
using namespace std;

#pragma pack(1)
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

class Base2
{
public:
    virtual void mybvirfunc2() {}
    int m_bi2;

public:
    Base2()
    {
        printf("Base2::Base2()构造函数的this指针是：%p!\n", this);
    }
};

class MYACLS : public Base, public Base2
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
#pragma pack()

int main()
{
    MYACLS aaa;
    cout << sizeof(MYACLS) << endl;
    printf("MYACLS::m_bi = %d\n", &MYACLS::m_bi);
    printf("MYACLS::m_bi2 = %d\n", &MYACLS::m_bi2);
    printf("MYACLS::m_i = %d\n", &MYACLS::m_i);
    printf("MYACLS::m_j = %d\n", &MYACLS::m_j);

    return 0;
}
// 运行结果
// Base::Base()构造函数的this指针是：0x7fff06869eb0!
// Base2::Base2()构造函数的this指针是：0x7fff06869ebc!
// MYACLS::MYACLS()构造函数的this指针是：0x7fff06869eb0!
// 32
// MYACLS::m_bi = 8
// MYACLS::m_bi2 = 8
// MYACLS::m_i = 24
// MYACLS::m_j = 28

/**
 * 多重继承且父类都有虚函数
 * this指针有调整。
 * 内存布局是父类vptr，然后是父类成员变量。
 * 最后是子类成员变量
 **/