#include <iostream>
using namespace std;

int operator"" _I(unsigned long long n)
{
    return n - 1;
}

int main()
{
    int val = 123_I;
    cout << val << endl;
}