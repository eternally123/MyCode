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

int main()
{
    shared_ptr<A> sp1 = make_shared<A>();
    weak_ptr<A> wp = sp1;
    shared_ptr<A> sp2(wp);
    cout << sp1.use_count() << endl;
    cout << sp2.use_count() << endl;
    cout << wp.use_count() << endl;
    return 0;
}