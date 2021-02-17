#include <stdio.h>
#include <iostream>

void f(int a, int b)
{
    std::cout << "f(int,int)\n";
}

void f(int a, char *b)
{
    std::cout << "f(int,char*)\n";
}

int main()
{
    int i = 10;
    f(i, 0);
    // f(i, NULL);
    f(i, nullptr);
}