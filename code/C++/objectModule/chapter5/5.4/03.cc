/**
 * 继承的非虚函数坑
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
};
class Derive : public Base
{
public:
    void myfunc()
    {
        cout << "Derive::myfunc()" << endl;
    }
};

int main()
{
    Derive derive;
    Derive *pderive = &derive;
    pderive->myfunc(); //Derive::myfunc()

    Base *pbase = &derive;
    pbase->myfunc(); //Base::myfunc(),这里调用的居然是父类的myfunc，是个陷阱，写程序时一定要注意
}

/**
 * 普通函数是静态绑定。即myfunc是静态绑定，到底执行哪个myfunc成员函数取决于调用者的静态类型。
 * pbase静态类型是Base，所以调用Base::myfunc
 * 
 * 虚函数时动态绑定，代码示例不再列举
 * 
 * 结论：不应该在子类中重新定义一个继承来的非虚函数
 **/