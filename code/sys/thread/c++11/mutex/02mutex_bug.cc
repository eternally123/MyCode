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
    func();
}

// 在main函数中调用mutex两次加锁无用？