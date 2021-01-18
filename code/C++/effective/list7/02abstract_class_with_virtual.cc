#include <iostream>
using namespace std;

class Base
{
public:
    Base() { cout << "Base()\n"; }
    Base(int num) { cout << "Base(int num)\n"; }
    virtual ~Base() = 0;
};
Base::~Base()
{
    cout << "~Base()\n";
}

class Derived : public Base
{
public:
    Derived() : Base(10) { cout << "Derived\n"; }
    virtual ~Derived() { cout << "~Derived\n"; }
};

int main()
{
    Base *base = new Derived();
    delete base;
}

/**
 * 1.派生类构造函数默认调用基类默认构造函数，可以显式指定调用哪个
 * 2.如果是virtual基类析构函数会被调用
 **/