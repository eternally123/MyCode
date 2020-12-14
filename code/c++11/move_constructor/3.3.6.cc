#include <iostream>

using namespace std;

class A
{
public:
    int num = 10;
};

int main()
{
    A a;
    A b = move(a);
    cout << &a.num << endl;
    cout << &b.num << endl;
    return 0;
}