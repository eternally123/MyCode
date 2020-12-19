#include "thread/mutex.hh"
#include "thread/log/log.hh"

Mutex::Mutex()
{
    int ret = pthread_mutex_init(&mutex_, nullptr);
    if (0 != ret)
    {
        ERROR_LOG("Syscall Error: pthread_mutex_init.");
    }
}

Mutex::~Mutex()
{
    try
    {
        int ret = pthread_mutex_destroy(&mutex_);
        if (0 != ret)
        {
            ERROR_LOG("Syscall Error: pthread_mutex_destroy.");
        }
    }
    catch (...)
    {
    }
}

int Mutex::lock()
{
    return pthread_mutex_lock(&mutex_);
}

int Mutex::trylock()
{
    return pthread_mutex_trylock(&mutex_);
}

int Mutex::unlock()
{
    return pthread_mutex_unlock(&mutex_);
}

pthread_mutex_t *Mutex::getPthreadMutex()
{
    return &mutex_;
}