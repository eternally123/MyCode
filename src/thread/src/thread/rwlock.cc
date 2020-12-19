#include "thread/rwlock.hh"
#include "thread/log/log.hh"

RWLock::RWLock()
{
    int ret = pthread_rwlock_init(&rwlock_, nullptr);
    if (0 != ret)
    {
        ERROR_LOG("Syscall Error: pthread_rwlock_init. ");
    }
}

RWLock::~RWLock()
{
    try
    {
        int ret = pthread_rwlock_destroy(&rwlock_);
        if (0 != ret)
        {
            ERROR_LOG("Syscall Error: pthread_rwlock_destory. ");
        }
    }
    catch (...)
    {
    }
}

int RWLock::readLock()
{
    return pthread_rwlock_rdlock(&rwlock_);
}

int RWLock::writeLock()
{
    return pthread_rwlock_wrlock(&rwlock_);
}

int RWLock::tryreadLock()
{
    return pthread_rwlock_tryrdlock(&rwlock_);
}

int RWLock::trywriteLock()
{
    return pthread_rwlock_trywrlock(&rwlock_);
}

int RWLock::unlock()
{
    return pthread_rwlock_unlock(&rwlock_);
}