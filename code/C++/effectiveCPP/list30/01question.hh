#include <iostream>
using namespace std;

class Base
{
public:
    Base() {}
    virtual ~Base() {}

public:
    virtual inline void print()
    {
        cout << "Base print\n";
        int *p = new int[10];
        count--;
        if (count > 0)
            print();
    }

private:
    int count = 10;
};

class Derived : public Base
{
public:
    Derived() {}
    virtual ~Derived() {}

public:
    virtual inline void print()
    {
        int *p = new int[100];
        cout << "Derived print\n";
    }
};