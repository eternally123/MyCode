#include <iostream>
using namespace std;

class Base
{
public:
    int healthValue() const
    {
        return doHealthValue();
    }

private:
    virtual int doHealthValue() const
    {
        return 0;
    }
};

class Derived : public Base
{

private:
    virtual int doHealthValue() const
    {
        return 1;
    }
};

int main()
{
    Base *b = new Derived();
    cout << b->healthValue() << endl;
}

/**
 * virtual的另外一种实现方式：
 * NVI方法/模板方法设计模式
 **/