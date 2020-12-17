#include "barrier.hh"
#include "log/log.hh"

Barrier::Barrier(int count)
{
    int ret = pthread_barrier_init(&barrier_, nullptr, count);
    if (0 != ret)
    {
        ERROR_LOG("Syscall Error:pthread_barrier_init. ");
    }
}

Barrier::~Barrier()
{
    try
    {
        int ret = pthread_barrier_destroy(&barrier_);
        if (0 != ret)
        {
            ERROR_LOG("Syscall Error:pthread_barrier_destroy. ");
        }
    }
    catch (...)
    {
    }
}

int Barrier::wait()
{
    return pthread_barrier_wait(&barrier_);
}