#include <stdio.h>
class A
{
public:
    virtual ~A(){};
    int a1;
    int a2;
};

class B : public A
{
public:
    virtual ~B(){};

public:
    int b1;
    int b2;
};

int main()
{
    printf("%d\n", &B::a1); //0
    printf("%d\n", &B::a2); //4
    printf("%d\n", &B::b1); //16
    printf("%d\n", &B::b2); //20
}
