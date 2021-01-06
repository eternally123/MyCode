#include "thread/thread.hh"
#include "thread/mutex.hh"
#include "thread/log/log.hh"

struct Info
{
    long long int count;
    Mutex lock;
};

class IOThread
{
public:
    void setInfo(Info *info)
    {
        pInfo_ = info;
    }
    virtual void run()
    {
        for (int i = 0; i < 100000000; i++)
        {
            pInfo_->lock.lock();
            pInfo_->count = pInfo_->count + 1;
            pInfo_->lock.unlock();
        }
    }

private:
    Info *pInfo_;
};

int main()
{
    Info *info = new Info();
    IOThread t1;
    IOThread t2;
    IOThread t3;
    t1.setInfo(info);
    t2.setInfo(info);
    t3.setInfo(info);
    t1.run();
    t2.run();
    t3.run();
    INFO_LOG("count=%d", info->count);

    // Mutex mu;
    // mu.lock();
    // mu.unlock();
    // mu.lock();
    // INFO_LOG("print something");
}