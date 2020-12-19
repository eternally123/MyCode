#include "thread/cond.hh"
#include "thread/log/log.hh"

Cond::Cond(MutexPtr mutex)
    : mutex_(mutex)
{
    int ret = pthread_cond_init(&cond_, nullptr);
    if (0 != ret)
    {
        ERROR_LOG("Syscall Error: pthread_cond_init. ");
    }
}

Cond::~Cond()
{
    try
    {
        int ret = pthread_cond_destroy(&cond_);
        if (0 != ret)
        {
            ERROR_LOG("Syscall Error: pthread_cond_destory. ");
        }
    }
    catch (...)
    {
    }
}

int Cond::wait()
{
    return pthread_cond_wait(&cond_, mutex_->getPthreadMutex());
}

int Cond::notify()
{
    return pthread_cond_signal(&cond_);
}

int Cond::notifyAll()
{
    return pthread_cond_broadcast(&cond_);
}