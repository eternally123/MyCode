#include <stdio.h>
#include <stdlib.h>

class A {
public:
    A() { j = new int(); }
    int i;
    int* j;
};

int main(void)
{
    A* a;
    a = new A();
    //     delete a;
    return 0;
}