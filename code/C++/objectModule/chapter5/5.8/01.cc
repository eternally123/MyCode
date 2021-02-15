/**
 * RTTI
 **/
#include <iostream>
using namespace std;

class Base
{
public:
    virtual void f() { cout << "Base::f()" << endl; }
    virtual void g() { cout << "Base::g()" << endl; }
    virtual void h() { cout << "Base::h()" << endl; }
    virtual ~Base() {}
};
class Derive : public Base
{
public:
    virtual void g() { cout << "Derive::g()" << endl; }
    void myselffunc() {} //只属于Derive的函数
    virtual ~Derive() {}
};

int main()
{
    Base *pb = new Derive();
    Derive myderive;
    Base &yb = myderive;
    cout << typeid(*pb).name() << endl; //class Derive
    cout << typeid(yb).name() << endl;  //class Derive
    Base *pb2 = new Derive();
    const std::type_info &tp2 = typeid(*pb2);
    cout << tp2.name() << endl;

    //---------------------------------------
    printf("tp2地址为 :%p\n", &tp2);

    long *pvptr = (long *)pb2;     //指向对象pb2的指针转成long *型,大家注意，目前pb2对象里只有虚函数表指针
    long *vptr = (long *)(*pvptr); //指向虚函数表(虚函数表首地址)

    printf("虚函数表首地址为:%p\n", vptr);
    printf("虚函数表首地址之前一个地址为:%p\n", vptr - 1); //注意，long在当前这个环境是4字节，所以vptr-1,其实得到的地址是往回走了4个地址

    //取得这个地址中的内容
    long *prttiiinfo = (long *)(*(vptr - 1));

    prttiiinfo += 3; //跳过12个字节
    long *ptypeinfoaddr = (long *)(*prttiiinfo);
    const std::type_info *ptypeinfoaddrreal = (const std::type_info *)ptypeinfoaddr;
    printf("ptypeinfoaddrreal地址为 :%p\n", ptypeinfoaddrreal);
    cout << ptypeinfoaddrreal->name() << endl; //结果class Derive

    cout << typeid(int).name() << endl; //输出int
}

/**
 * Q:利用vs可以跑通，但是gcc不行。可能是编译器对RTTI的实现不同。
 **/