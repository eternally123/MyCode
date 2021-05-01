#include <iostream>
#include <time.h>
#include <cstdio>

using namespace std;

class Grand //爷爷类
{
public:
    int m_grand;
};
class A1 : public Grand
{
public:
};
class A2 : public Grand
{
public:
};
class C1 : public A1, public A2
{
public:
};

int main()
{
    cout << sizeof(Grand) << endl; //4
    cout << sizeof(A1) << endl;    //4
    cout << sizeof(A2) << endl;    //4
    cout << sizeof(C1) << endl;    //8

    C1 c1;
    // c1.m_grand = 1; // 编译报错，二义性
    c1.A1::m_grand = 1;
    c1.A2::m_grand = 2;

    return 0;
}

/**
 * 无虚函数时，菱形继承。
 **/