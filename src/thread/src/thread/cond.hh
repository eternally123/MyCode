#pragma once
#include "utils/class_constructor.hh"
#include "mutex.hh"

#include <memory>

#include "pthread.h"

class Cond : public nocopyable, public nomoveable
{
    using MutexPtr = std::shared_ptr<Mutex>;

public:
    Cond(MutexPtr mutex);
    ~Cond();

public:
    int wait();
    int notify();
    int notifyAll();

private:
    pthread_cond_t cond_;
    MutexPtr mutex_;
};