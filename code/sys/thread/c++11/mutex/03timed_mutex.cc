#include <mutex>
#include <thread>
#include <iostream>

using namespace std;

void func()
{
    timed_mutex mu;
    std::cout << mu.try_lock_for(chrono::seconds(1)) << endl;
    std::cout << mu.try_lock_for(chrono::seconds(1)) << endl;
}

int main()
{
    thread t1(func);
    t1.detach();
    this_thread::sleep_for(chrono::seconds(2));
}

// 在main函数中调用mutex两次加锁无用？