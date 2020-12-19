#include "thread/spin.hh"

#include "thread/log/log.hh"

Spin::Spin()
{
    int ret = pthread_spin_init(&lock_, PTHREAD_PROCESS_PRIVATE);
    if (0 != ret)
    {
        ERROR_LOG("Syscall Error:pthread_spin_init. ");
    }
}

Spin::~Spin()
{
    try
    {
        int ret = pthread_spin_destroy(&lock_);
        if (0 != ret)
        {
            ERROR_LOG("Syscall Error:pthread_spin_destory. ");
        }
    }
    catch (...)
    {
    }
}

int Spin::lock()
{
    return pthread_spin_lock(&lock_);
}

int Spin::trylock()
{
    return pthread_spin_trylock(&lock_);
}

int Spin::unlock()
{
    return pthread_spin_unlock(&lock_);
}