#include <iostream>
#include <time.h>
#include <cstdio>

using namespace std;

class Base1
{
public:
    int m_i1;
    char m_c1;
};

class Base2 : public Base1
{
public:
    char m_c2;
};

class Base3 : public Base2
{
public:
    char m_c3;
};

int main()
{
    cout << sizeof(Base1) << endl; // 8
    cout << sizeof(Base2) << endl; // 12
    cout << sizeof(Base3) << endl; // 12

    printf("Base3::m_i1 = %d\n", &Base3::m_i1); // 0
    printf("Base3::m_c1 = %d\n", &Base3::m_c1); // 4
    printf("Base3::m_c2 = %d\n", &Base3::m_c2); // 8
    printf("Base3::m_c3 = %d\n", &Base3::m_c3); // 9
}

/**
 * 在引入继承关系后，父类子类的成员变量布局在不同编译器下结果不同。
 * 也不太理解gcc为什么这么布局。
 * 但是vs2017的布局倒是很好理解。就是每个类都做内存对齐。
 **/