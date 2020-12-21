#include "thread/threadpool.hh"
#include "thread/thread.hh"
#include "thread/log/log.hh"

#include <iostream>

#include <unistd.h>

class Task : public BaseTask
{
public:
    Task(std::function<void()> f)
        : BaseTask(f)
    {
    }

    static void task()
    {
        int value = 0;
        for (int i = 1; i < 10; i++)
        {
            value = value + i;
        }
        INFO_LOG("result= %d", value);
        std::cout << value << std::endl;
    }
};

int main()
{
    ThreadPool pool;
    pool.start();
    Task *t = new Task(Task::task);
    pool.addTask(t);
    pool.addTask(t);
    pool.addTask(t);
    pool.addTask(t);
    pool.addTask(t);
    INFO_LOG("task %p", t);
    sleep(4);
}