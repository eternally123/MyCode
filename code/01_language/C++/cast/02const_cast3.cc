#include <iostream>

using namespace std;

const int a = 100;
int main()
{
    int *pa = const_cast<int *>(&a);
    *pa = 110;
    printf("%d,\n", a);
    printf("%d,\n", *pa);
    printf("0x%08x\n", &a);
    printf("0x%08x\n", pa);
}