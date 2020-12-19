#pragma once
#include "thread/utils/class_constructor.hh"

#include "pthread.h"

class Spin : public nocopyable, public nomoveable
{
public:
    Spin();
    ~Spin();

public:
    int lock();
    int trylock();
    int unlock();

private:
    pthread_spinlock_t lock_;
};