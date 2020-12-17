#pragma once
#include "class_constructor.hh"

#include <pthread.h>

class Mutex : public nocopyable, public nomoveable
{
public:
    Mutex();
    ~Mutex();

public:
    int init();
    int destory();
    int lock();
    int trylock();
    int unlock();

private:
    pthread_mutex_t mutex_;
};