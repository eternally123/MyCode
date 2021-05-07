#include <stdio.h>
class A
{
public:
    A() { printf("A this=%p\n", this); };
    int a1;
    int a2;
};

class B : public A
{
public:
    B() { printf("B this=%p\n", this); };
    virtual ~B(){};

public:
    int b1;
    int b2;
};

int main()
{
    B b;
}
