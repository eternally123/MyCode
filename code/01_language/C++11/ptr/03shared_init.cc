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
    // shared_ptr<A> sp = make_shared<A>();
    shared_ptr<A> sp(new A());
    shared_ptr<A> sp2(sp);
    cout << sp.use_count() << endl;
}

void f2()
{
}

int main()
{
}