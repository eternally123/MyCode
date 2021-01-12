#include <condition_variable>
#include <mutex>
#include <thread>
#include <chrono>
#include <iostream>

using namespace std;

mutex mtx;             // 全局互斥锁.
condition_variable cv; // 全局条件变量.
bool ready = false;    // 全局标志位.

void do_print_id(int id)
{
    unique_lock<mutex> lck(mtx);
    while (!ready)    // 如果标志位不为 true, 则等待...
        cv.wait(lck); // 当前线程被阻塞, 当全局标志位变为 true 之后,
                      // 线程被唤醒, 继续往下执行打印线程编号id.
    cout << "thread " << id << '\n';
}

void go()
{
    unique_lock<mutex> lck(mtx);
    ready = true; // 设置全局标志位为 true.
    // cv.notify_all(); // 唤醒所有线程.
    cv.notify_one();
    cv.notify_one();
}

int main()
{
    thread threads[10];
    // spawn 10 threads:
    for (int i = 0; i < 10; ++i)
    {
        threads[i] = thread(do_print_id, i);
        threads[i].detach();
    }

    cout << "10 threads ready to race...\n";
    this_thread::sleep_for(chrono::seconds(1));
    go(); // go!
    this_thread::sleep_for(chrono::seconds(1));

    return 0;
}

// condition_variable是条件变量的封装，使用时需要用到unique_lock
// https://www.cnblogs.com/haippy/p/3252041.html