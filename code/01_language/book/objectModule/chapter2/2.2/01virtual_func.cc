#include <iostream>
using namespace std;

class A
{
public:
    virtual void myfunc(){};
};

int main()
{
    A a;
    cout << sizeof(a) << endl;
}