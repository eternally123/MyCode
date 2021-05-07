#include <stdio.h>
// #include <iostream>
using namespace std;

class A
{
public:
    A() { printf("A this=%p\n", this); };
    // virtual ~A(){};
    int a1;
    // int a2;
};
class B : public A
{
public:
    B() { printf("B this=%p\n", this); }
    // virtual ~B(){};
    // int b1;
};

class C : public A
{
public:
    C() { printf("C this=%p\n", this); };
    // virtual ~C(){};

public:
    // int c1;
    // int c2;
};

class D : public B, public C
{
};

int main()
{
    // cout << sizeof(A) << endl;
    // cout << sizeof(B) << endl;
    // cout << sizeof(C) << endl;
    // cout << sizeof(D) << endl;

    D d;
    d.B::a1;
}
