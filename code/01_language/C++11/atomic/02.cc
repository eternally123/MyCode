#include <iostream>
#include <atomic>

using namespace std;

int main()
{
    atomic<int> a = {10};
    int expect = 10;
    cout << a.compare_exchange_weak(expect, 5) << endl;
    cout << a << endl;
}