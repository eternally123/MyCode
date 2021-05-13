#include <iostream>

using namespace std;

class A
{
};

class B : public A
{
public:
    void printa() { cout << "B" << i << endl; }
    int i = 10;
};

class C : public A
{
public:
    void print() { cout << "C" << j << endl; }
    int j = 0;
};

int main()
{
    A a;
    C c;
    B b;
    {
        A a1 = static_cast<A>(b);
        // A a2 = static_cast<C>(c);
        A *a3 = static_cast<A *>(&b);
        B *b1 = static_cast<B *>(&a);
        // A *a4 = static_cast<A *>(&c);
    }

    {
        A *a1 = static_cast<A *>(&b);
        C *c1 = static_cast<C *>(a1);
        cout << "finish cast:&b =" << &b << "  *c1=" << c1 << endl;
        c1->print();
    }
}