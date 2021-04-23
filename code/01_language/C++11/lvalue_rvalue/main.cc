#include <iostream>
using namespace std;

class A
{
public:
    A() { cout << "A()\n"; };
    A(const A &) { cout << "A(const&)\n"; }
    // A(A &) { cout << "A(&)\n"; }
    A(A &&) { cout << "A(&&)\n"; }
    // A(const A &&) { cout << "A(const&&)\n"; }
    ~A() { cout << "~A()\n"; };
    int num = 10;
};

A f()
{
    return A();
}

int main()
{
    A val = f(); //非引用返回的函数的临时变量是纯右值
    cout << val.num << endl;
}
/**
 * A &&val = f();
 * A()  A(&&)  ~A()  10  ~A()
 * 
 * A val = f()
 * A()  A(&&)  ~A()  A(&&)  ~A()  10  ~A()
 **/