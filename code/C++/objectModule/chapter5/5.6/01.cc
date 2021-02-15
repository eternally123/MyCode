/**
 * 多继承下
 **/
#include <iostream>
using namespace std;

class Base
{
public:
    virtual void f() { cout << "Base::f()" << endl; }
    virtual void g() { cout << "Base::g()" << endl; }
    virtual void h() { cout << "Base::h()" << endl; }
};

class Base2
{
public:
    virtual void hBase2() { cout << "Base2::hBase2()" << endl; }
    ~Base2() { cout << "Base2::~Base2()" << endl; }
    // virtual ~Base2() { cout << "Base2::~Base2()" << endl; }
};

class Derive : public Base, public Base2
{
public:
    virtual void i() { cout << "Derive::i()" << endl; }
    virtual void g() { cout << "Derive::g()" << endl; }
    void myselffunc() {} //只属于Derive的函数
};

int main()
{
    Base2 *pbase2 = new Derive();
    delete pbase2; // 打印完cout语句后，invalid pointer
    // 如果是虚析构函数，则不会报异常
}

/**
 * delete时会出现invalid pointer，然后core dump
 * Q:为什么会这样？
 * A:delete时调用析构函数，此时pbase2的析构函数是非虚函数，所以调用静态绑定的析构函数。
 * delete掉pb2开头的这段内存。因为不是new返回的内存起始地址，所以报错。
 * 
 * 而改为虚函数，调用时根据动态类型调用到Derive的析构函数，即能正常调用。
 **/