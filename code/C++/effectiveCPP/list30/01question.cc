#include <iostream>
using namespace std;

class Base
{
public:
    Base() {}
    virtual ~Base() {}

public:
    inline virtual void print()
    {
        cout << "Base print\n";
    }
};

class Derived : public Base
{
public:
    Derived() {}
    virtual ~Derived() {}

public:
    inline virtual void print()
    {
        cout << "Derived print\n";
    }
};

int main()
{
    Base *b = new Derived();
    b->print();
}

/**
 * g++ -O -Winline  main.cc 为什么不报警告信息？？？不知道为什么
 **/