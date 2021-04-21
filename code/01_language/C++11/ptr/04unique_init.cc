#include <iostream>
#include <memory>

using namespace std;

class A
{
public:
    A() { cout << "A()\n"; }
    ~A() { cout << "~A()\n"; }
};

void f1()
{
    unique_ptr<A> up(new A());
    unique_ptr<A> up2(up.release());
}

void f2()
{
    A *a = new A();
    unique_ptr<A> up(a);
    cout << (up.release() == a) << endl;
    // 内存泄漏，release返回裸指针
    // reset相当于析构原指针，然后接管传入的裸指针。
}

int main()
{
    f2();
}