#include <iostream>
#include <memory>

using namespace std;

class B;

class A
{
public:
    A() { cout << "A\n"; }
    ~A() { cout << "~A()\n"; }
    void set(shared_ptr<B> b) { b_ = b; }
    weak_ptr<B> b_;
};

class B
{
public:
    B() { cout << "B\n"; }
    ~B() { cout << "~B()\n"; }
    void set(shared_ptr<A> a) { a_ = a; }
    shared_ptr<A> a_;
};

int main()
{
    shared_ptr<B> b = make_shared<B>();
    shared_ptr<A> a = make_shared<A>();
    a->set(b);
    b->set(a);
}
// 会存在内存泄漏，因为存在环形引用计数问题
// 解决方法，将一个指针换为weak_ptr即可