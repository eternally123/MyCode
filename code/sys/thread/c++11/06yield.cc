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
        {
            cout << i << endl;
            if (2 == i)
                this_thread::yield();
        }
    }
};

int main()
{
    PrintThread t;
    thread t1(&PrintThread::dummy, &t, 5);
    thread t2(&PrintThread::dummy, &t, 6);
    t1.detach();
    t2.detach();

    this_thread::sleep_for(chrono::seconds(2));
}

// yield会让当前线程让出CPU时间片。此示例可能不会有预期结果，因为创建t2时可能t1已经运行完
// 即t1让出CPU时间片后，让给了main函数