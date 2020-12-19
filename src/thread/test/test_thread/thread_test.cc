#include "thread/thread.hh"
#include "thread/log/log.hh"

#include <unistd.h>

#include <iostream>

class IOThread : public Thread
{
public:
    virtual void run()
    {
        INFO_LOG("thread run...");
    }
};

int main()
{
    IOThread thread;
    thread.start();
    sleep(2);
}