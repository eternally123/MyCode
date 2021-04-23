#include <iostream>
using namespace std;

int f()
{
    return 1;
}

int main()
{
    int &&val = f(); //非引用返回的函数的临时变量是纯右值
    cout << val << endl;
}