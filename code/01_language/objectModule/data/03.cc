#include <stdio.h>
class A
{
public:
    A() { printf("A this=%p\n", this); };
    // virtual ~A(){};
    int a1;
    int a2;
};
class B
{
public:
    B() { printf("B this=%p\n", this); }
    // virtual ~B(){};
    int b1;
};

class C : public A, public B
{
public:
    C() { printf("C this=%p\n", this); };
    virtual ~C(){};

public:
    int c1;
    int c2;
};

int main()
{
    C c;
}
