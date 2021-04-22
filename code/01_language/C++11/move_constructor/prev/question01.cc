#include <iostream>

using namespace std;

class A
{
public:
    A() { cout << "A()\n"; }
    A(const A &) { cout << "A(const A&)\n"; }
    ~A() { cout << "~A()\n"; }
    int num;
};

A func()
{
    A a = A();
    a.num = 10;

    return a;
}

int main()
{
    func();
}
/**
 * 
A()
A(const A&)
~A()
A(const A&)
~A()
~A()

 **/