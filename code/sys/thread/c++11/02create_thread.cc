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
    t1.detach();
    t2.detach();
    this_thread::sleep_for(chrono::seconds(1));
    // t1.join();
    // t2.join();
}

// 需要detach或join，否则会报thread对象析构会调用std::terminate结束线程，如果线程已经运行完会报异常