#include <iostream>

using namespace std;

class T
{
public:
    T() { cout << "T constructor\n"; }
    T(T &&t) { cout << "T move constructor\n"; }
    // T(const T &&t) { cout << "T move constructor\n"; }
};

class Constructor
{
public:
    Constructor() { cout << "constructor\n"; }
    ~Constructor() { cout << "~constructor\n"; }
    Constructor(Constructor &mc) { cout << "copy constructor\n"; }
    Constructor(const Constructor &mc) { cout << "copy constructor\n"; }
    // Constructor(Constructor &&mc) : num(mc.num), p(mc.p), t(move(mc.t)) { cout << "move constructor\n"; }
    // Constructor(Constructor &&) = delete;

    void print() { cout << "print\n"; }
    int num;
    int *p;
    T t;
};

Constructor get()
{
    Constructor c;
    cout << &c << endl;
    cout << &c.num << endl;
    cout << &c.t << endl;
    return c;
}

int main()
{
    Constructor c = get();
    cout << &c << endl;
    cout << &c.num << endl;
    cout << &c.t << endl; // ？这里为什么地址不一样？用move完成了移动构造应该一样啊
}