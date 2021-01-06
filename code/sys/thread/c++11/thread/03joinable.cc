#include <thread>
#include <chrono>
#include <iostream>

using namespace std;

void dummy(int n)
{
    for (int i = 0; i < n; i++)
        cout << i << " ";
}

int main()
{
    thread t1(dummy, 100);
    thread t2(dummy, 500);
    cout << "\n"
         << t1.joinable() << "\n";

    t1.detach();
    cout << "\n"
         << t1.joinable() << "\n";
    t2.detach();
    this_thread::sleep_for(chrono::seconds(1));
}

// joinable会返回是否可join，即可用用来判断线程状态时joinable还是detach。结果为01