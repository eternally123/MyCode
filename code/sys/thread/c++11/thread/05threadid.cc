#include <thread>
#include <chrono>
#include <iostream>

using namespace std;

class PrintThread //类中的数据访问要注意多线程访问问题
{
public:
    void dummy(int n)
    {
        cout << this_thread::get_id() << endl;

        for (int i = 0; i < n; i++)
        {
        }
    }

private:
    int count;
};

int main()
{
    cout << this_thread::get_id() << endl;
    PrintThread t;
    thread t1(&PrintThread::dummy, &t, 100);
    cout << t1.native_handle() << endl;
    cout << t1.get_id() << endl;
    t1.detach();
    this_thread::sleep_for(chrono::seconds(1));
}

// 获取线程id的两种方式：native_handle 和this_thread::get_id