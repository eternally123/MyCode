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