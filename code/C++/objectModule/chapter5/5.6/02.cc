/**
 * 判断多态体系调用哪个函数
 **/
#include <iostream>
using namespace std;

class Base
{
public:
    void test() { cout << "test\n"; }
};

class Derive : public Base
{
public:
    virtual void test() { cout << "test1\n"; }
};

class Son : public Derive
{
    virtual void test() { cout << "test2\n"; }
};

int main()
{
    Base *pBase = new Son();
    pBase->test(); // test
}

/**
 * 调用的是Base的test函数。而Base的test函数不是虚函数，是普通函数。
 * 所以执行时取决于调用者的静态类型，即Base。
 * 故最终调用Base::test
 **/