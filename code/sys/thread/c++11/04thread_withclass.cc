#include <thread>
#include <chrono>
#include <iostream>

using namespace std;

class PrintThread //类中的数据访问要注意多线程访问问题
{
public:
    void dummy(int n)
    {
        for (int i = 0; i < n; i++)
            cout << i << "=";
    }

private:
    int count;
};

int main()
{
    PrintThread t;
    thread t1(&PrintThread::dummy, &t, 100);
    thread t2(&PrintThread::dummy, &t, 500);
    t1.detach();
    t2.detach();
    this_thread::sleep_for(chrono::seconds(1));
}

// 将线程函数封装到类中