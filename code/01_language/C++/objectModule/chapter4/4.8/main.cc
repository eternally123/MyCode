#include <iostream>
#include <time.h>
#include <cstdio>

using namespace std;

#pragma pack(1)
class Grand //爷爷类
{
public:
    int m_grand;
};
class A1 : virtual public Grand
{
public:
};
class A2 : virtual public Grand
{
public:
};
class C1 : public A1, public A2
{
public:
};
#pragma pack()

int main()
{
    cout << sizeof(Grand) << endl; //4
    cout << sizeof(A1) << endl;    //12=4+8
    cout << sizeof(A2) << endl;    //12=4+8
    cout << sizeof(C1) << endl;    //20=4+8+8

    // C1 c1;
    // c1.m_grand = 0;
    // c1.A1::m_grand = 1;
    // c1.A2::m_grand = 2;

    return 0;
}

/**
 * 无虚函数时，菱形继承。且虚继承
 * Q:目前还不清楚为什么类的大小变得很大
 * A:这是因为引入了虚基类表，虚基类表指针vbptr。
 **/