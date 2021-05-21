#include <iostream>
#include <condition_variable>
#include <thread>
#include <chrono>

std::condition_variable_any cv;
std::mutex cv_m; // This mutex is used for three purposes:
                 // 1) to synchronize accesses to i
                 // 2) to synchronize accesses to std::cerr
                 // 3) for the condition variable cv
int i = 0;

void waits()
{
    std::unique_lock<std::mutex> lk(cv_m);
    std::cerr << "Waiting... \n";
    //相当于while循环，可以看源码
    cv.wait(lk, []
            { return i == 1; });
    std::cerr << "...finished waiting. i == 1\n";
}

void signals()
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
    {
        std::lock_guard<std::mutex> lk(cv_m);
        std::cerr << "Notifying...\n";
    }
    cv.notify_all();

    std::this_thread::sleep_for(std::chrono::seconds(1));

    std::lock_guard<std::mutex> lk(cv_m);
    i = 1;
    std::cerr << "Notifying again...\n";

    //sleep 5s 由于lc没有释放cv_m的lock，会导致消费者线程被唤醒，然后又因为无法拿到cv_m的lock而睡眠，直到本线程释放lock
    std::this_thread::sleep_for(std::chrono::seconds(5));

    cv.notify_all();
}

int main()
{
    std::thread t1(waits), t2(waits), t3(waits), t4(signals);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
}