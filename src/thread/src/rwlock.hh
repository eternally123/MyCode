#pragma once
#include "class_constructor.hh"

#include <pthread.h>

class RWLock : public nocopyable, public nomoveable
{
public:
    RWLock();
    ~RWLock();

public:
    int readLock();
    int tryreadLock();
    int writeLock();
    int trywriteLock();
    int unlock();

private:
    pthread_rwlock_t rwlock_;
};