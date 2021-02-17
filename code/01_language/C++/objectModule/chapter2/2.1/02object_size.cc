#include <iostream>
using namespace std;

class A
{
public:
    char ch;
};

int main()
{
    A a;
    cout << sizeof(a) << endl; // 空对象也有一个字节大小
}