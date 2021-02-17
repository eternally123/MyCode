#include <thread>
#include <mutex>
#include <chrono>
#include <iostream>

using namespace std;

void init_count()
{
    cout << "should call once" << endl;
}

void call_func()
{
    static once_flag once;
    call_once(once, init_count);
    call_once(once, init_count);
}

int main()
{
    thread t1(call_func);
    thread t2(call_func);
    thread t3(call_func);
    thread t4(call_func);
    t1.detach();
    t2.detach();
    t3.detach();
    t4.detach();
    this_thread::sleep_for(chrono::seconds(1));
}

// call_once保证函数多线程下调用只执行一次