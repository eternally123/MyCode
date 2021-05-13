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
    const int a = 100;
    int *pa = const_cast<int *>(&a);
    *pa = 110;
    printf("%d,\n", a);
    printf("%d,\n", *pa);
    printf("0x%08x\n", &a);
    printf("0x%08x\n", pa);
}