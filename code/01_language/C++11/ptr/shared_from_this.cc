#include <cstdlib>
#include <iostream>
#include <memory>
#include <utility>
#include <boost/asio.hpp>
#include <vector>

using namespace std;

class A
{
};

class B : public A
{
};

class C
{
};

void f(A *a)
{
    cout << "a\n";
}

void f(...)
{
    cout << "b\n";
}

int main()
{
    B *b = nullptr;
    C *c = nullptr;
    f(b);
    f(c);
    f(1, 2, 3);
}

// int main()
// {
//     shared_ptr<A> sp1 = make_shared<A>();
//     weak_ptr<A> wp = sp1;
//     shared_ptr<A> sp2(wp);
//     cout << sp1.use_count() << endl;
//     cout << sp2.use_count() << endl;
//     cout << wp.use_count() << endl;
//     return 0;
// }