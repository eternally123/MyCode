#include <iostream>
#include <string>

using namespace std;
class Base
{
public:
    Base() {}
    virtual ~Base() {}

    void init(string log)
    {
        printLog(log);
    }

    virtual void printLog(string log)
    {
        cout << log + " :log to stdcout" << endl;
    }
};

class Derived : public Base
{
public:
    Derived() {}
    virtual ~Derived() {}
    virtual void printLog(string log) override
    {
        cout << log + " :log to file" << endl;
    }
};

int main()
{
    Derived d;
    d.init("mylog");
}