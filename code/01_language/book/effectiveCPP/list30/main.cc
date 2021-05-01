// #include <iostream>
using namespace std;

int delta = 1;

class Base
{
public:
    Base() {}
    virtual ~Base() {}

public:
    virtual inline void print()
    {
        int b = delta;
        // cout << "Base print\n";
    }
};

class Derived : public Base
{
public:
    Derived() {}
    virtual ~Derived() {}

public:
    virtual inline void print()
    {
        int d = delta;
        // cout << "Derived print\n";
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