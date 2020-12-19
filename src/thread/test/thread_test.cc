#include "thread/thread.hh"
#include "log/log.hh"

#include <unistd.h>

#include <iostream>

class IOThread : public Thread
{
public:
    virtual void run()
    {
        std::cout << "thread run\n";
    }
};

int main()
{
    IOThread thread;
    thread.start();
    sleep(2);
}