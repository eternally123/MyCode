#include <iostream>
#include <memory>

using namespace std;

class A
{
public:
    A() { cout << "A()\n"; }
    ~A() { cout << "~A()\n"; }
};

void f2(weak_ptr<A> wp)
{
    if (wp.lock())
        cout << "object exsits now" << endl;
}

void f1()
{
    shared_ptr<A> sp;
    sp = make_shared<A>();
    weak_ptr<A> wp(sp);
    f2(wp);
}

int main()
{
    f1();
}