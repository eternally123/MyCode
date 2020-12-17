#pragma once
#include "class_constructor.hh"

#include <pthread.h>

class Mutex : public nocopyable, public nomoveable
{
    friend class Cond;

public:
    Mutex();
    ~Mutex();

public:
    int lock();
    int trylock();
    int unlock();

private:
    pthread_mutex_t *getPthreadMutex();

private:
    pthread_mutex_t mutex_;
};