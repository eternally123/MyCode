#include <iostream>
using namespace std;

template <typename T>
void myswap(T &a, T &b)
{
    cout << "myswap\n";
}

template <> //模板特化
void myswap<int>(int &a, int &b)
{
    cout << "myswap int\n";
}

int main()
{
    int a = 1;
    int b = 2;
    double c = 1.0;
    double d = 2.0;
    myswap(a, b);
    myswap(c, d);
}