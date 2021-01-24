#include <iostream>

class Base
{
public:
    void mf1() { std::cout << "Base::mf1\n"; }
};

class Derived : public Base
{
public:
    void mf1() { std::cout << "Derived::mf1\n"; }
};

int main()
{
    Base *b = new Derived();
    b->mf1();
}

/**
 * no-virtual是说基类提供强制实现。（但不是说任何情况派生类都不能用自己的实现，如果不用指针，然后复写也可以，但者破坏了设计原则，不应该这么做）
 * virtual是说基类提供默认实现。
 * pure-virtual是说基类不提供实现，派生类必须自己实现。
 **/
