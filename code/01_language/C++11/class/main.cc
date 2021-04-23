#include <iostream>

using namespace std;

class A
{
public:
    // private:
    virtual void f() { cout << "virtual A::f()\n"; }
};

class B : public A
{
public:
    void func() { f(); }

private:
    virtual void f() { cout << "virtual B::f()\n"; }
};

int main()
{
    A *a = new B();
    a->f();
}