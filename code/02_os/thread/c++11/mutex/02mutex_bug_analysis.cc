#include <mutex>
#include <thread>
#include <iostream>

using namespace std;
timed_mutex mu;

void func()
{
    // std::cout << mu.try_lock_for(chrono::seconds(1)) << endl;
    // std::cout << mu.try_lock_for(chrono::seconds(1)) << endl;
}

int main()
{
    mu.lock();
    thread t1(func);
    t1.detach();
    this_thread::sleep_for(chrono::seconds(2));
    mu.lock();
    cout << "print something" << endl;
}

// 原因在于__pthread_key_create地址，可以看lock的源码