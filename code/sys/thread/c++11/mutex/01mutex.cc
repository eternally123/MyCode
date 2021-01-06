#include <mutex>
#include <thread>
#include <iostream>

using namespace std;

void func()
{
    mutex mu;
    mu.lock();
    mu.lock();

    for (int i = 0; i < 10; i++)
    {
        mu.lock();
        cout << i << "\t";
    }
}

int main()
{
    thread t1(func);
    t1.detach();
    this_thread::sleep_for(chrono::seconds(3));
}

// mutex的加锁与解锁，与pthread_mutex一样