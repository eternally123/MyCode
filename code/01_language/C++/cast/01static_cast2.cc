#include <iostream>

using namespace std;

class A
{
    virtual void print2(){};
    virtual void print1(){};
};

class B : public A
{
public:
    void print1()
    {
        cout << "B1" << endl;
    }
    void print2()
    {
        cout << "B2" << endl;
    }
    char c = 'a';
};

class C : public A
{
public:
    void print2()
    {
        cout << "C2" << endl;
    }
    void print1()
    {
        cout << "C1" << endl;
    }
    int j = 0;
};

int main()
{
    // A a;
    // C c;
    // B b;
    // A *a1 = static_cast<A *>(&b);
    // C *c1 = static_cast<C *>(a1);
    //cout << "finish cast:&b =" << &b << "  *c1=" << c1 << endl;
    // c1->print1();
}