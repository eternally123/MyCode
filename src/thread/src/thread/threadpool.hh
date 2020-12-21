#pragma once
#include "thread/thread.hh"
#include "thread/utils/class_constructor.hh"

class ThreadPool : public nocopyable, public nomoveable
{
public:
private:
    int thread_num_;
};