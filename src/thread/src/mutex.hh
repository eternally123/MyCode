#pragma once

#include <pthread.h>

class Mutex
{
public:
    Mutex();
    ~Mutex();

private:
    pthread_mutex_t mutex_;
};