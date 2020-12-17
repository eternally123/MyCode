#include <iostream>

using namespace std;
class noncopyable
{
protected:
    noncopyable() {}
    virtual ~noncopyable() {}

public:
    // don't define these members
    noncopyable(const noncopyable &nc) = delete;
    noncopyable &operator=(const noncopyable &nc) = delete;
};

class A : public noncopyable
{
public:
    A(){};
    // A(const A &a) = default;
};

class T
{
public:
    T() { cout << "T\n"; };
    T(const T &t) { cout << "T copy\n"; };
    // T(const T &t) = delete;
};

class M : public T
{
public:
    M() { cout << "M\n"; };
    M(const M &m) : T(m) { cout << "M copy\n"; };
    // M(const M &m) = default;
};

int main()
{
    // M m;
    // M n = m;

    A a;
    // A b = a;
}

// $ ./a.out
// T
// M
// T
// M copy
// 说明：子类对象创建时会调用父类默认拷贝构造。
//      子类对象拷贝构造时也会先调用父类的构造。这样是错误的。