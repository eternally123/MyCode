#pragma once
#include "thread/utils/class_constructor.hh"

#include "pthread.h"

class Barrier : public nocopyable, public nomoveable
{
public:
    Barrier(int count);
    ~Barrier();

public:
    int wait();

private:
    pthread_barrier_t barrier_;
};