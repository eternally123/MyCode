/**
 * 重新定义虚函数缺省参数的坑
 **/
#include <iostream>
using namespace std;

class Base
{
public:
    void myfunc()
    {
        cout << "Base::myfunc()" << endl;
    }
    virtual void myvirfunc(int value = 1)
    {
        cout << "Base::myvirfunc(),value=" << value << endl;
    }
};
class Derive : public Base
{
public:
    void myfunc()
    {
        cout << "Derive::myfunc()" << endl;
    }
    virtual void myvirfunc(int value = 2)
    {
        cout << "Derive::myvirfunc(),value=" << value << endl;
    }
};

int main()
{
    Derive derive;
    Base base;
    Derive *pderive = &derive;
    Base *pbase = &derive;

    pderive->myvirfunc(); //Derive::myvirfunc()
    pbase->myvirfunc();   //Derive::myvirfunc()
    pbase = &base;
    pbase->myvirfunc(); //Base::myvirfunc()
}

/**
 * 运行结果：
 * Derive::myvirfunc(),value=2
 * Derive::myvirfunc(),value=1
 * Base::myvirfunc(),value=1
 * 
 * 缺省参数的静态绑定
 **/