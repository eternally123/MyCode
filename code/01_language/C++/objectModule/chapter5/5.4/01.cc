/**
 * 静态类型与动态类型
 **/
#include <iostream>
using namespace std;

class Base
{
};

class Derive : public Base
{
};

class Derive2 : public Base
{
};

int main()
{
    Base base;                    //静态类型是Base
    Derive derive;                //静态类型是Derive
    Base *pbase;                  //别管指向啥，反正定义的时候定义的是Base *，所以静态类型是Base *
    Base *pbase2 = new Derive();  //静态类型依旧是Base *
    Base *pbase3 = new Derive2(); //静态类型依旧是Base *
}

/**
 * 静态类型是编译期间确定好的
 * 动态类型是运行时候对象目前所指向的类型。一般只有指针和引用才有动态类型说法。
 **/