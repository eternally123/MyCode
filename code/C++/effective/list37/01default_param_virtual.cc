#include <iostream>
using namespace std;

class Base
{
public:
    virtual void print(int num = 1)
    {
        cout << num << endl;
    }
};

class Derived : public Base
{
    virtual void print(int num = 2)
    {
        cout << num << endl;
    }
};

int main()
{
    Base *b = new Derived();
    b->print();
}

/**
 * 不要重定义继承来的缺省参数值（virtual函数）
 **/