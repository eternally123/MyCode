#include "thread/threadpool.hh"
#include "thread/thread.hh"
#include "thread/log/log.hh"

#include <iostream>

#include <unistd.h>

class Task : public BaseTask
{
public:
    Task()
    {
    }

    virtual void job()
    {
        int value = 0;
        for (int i = 1; i < 10; i++)
        {
            value = value + i;
        }
        INFO_LOG("result= %d", value);
        sleep(1);
    }
};

int main()
{
    ThreadPool pool(2);
    pool.start();
    Task *t = new Task();
    pool.addTask(t);
    pool.addTask(t);
    pool.addTask(t);
    pool.addTask(t);
    pool.addTask(t);
    sleep(4);
}