#include "thread.hh"
#include "types.hh"

#include <climits>
#include <ctime>
#include <cstring>

#include <iostream>

ThreadID::ThreadID(const pthread_t &tid)
    : tid_(tid)
{
}

ThreadID::ThreadID(const ThreadID &tid)
    : tid_(tid.getID())
{
}

ThreadID &ThreadID::operator=(const ThreadID &tid)
{
    this->tid_ = tid.tid_;
    return *this;
}

bool ThreadID::operator==(const ThreadID &tid)
{
    return pthread_equal(this->tid_, tid.tid_) ? true : false;
}

bool ThreadID::operator!=(const ThreadID &tid)
{
    return pthread_equal(this->tid_, tid.tid_) ? false : true;
}

pthread_t ThreadID::getID() const
{
    return tid_;
}

Thread::Thread()
    : running_(false),
      detached_(false)
{
}

Thread::~Thread()
{
    try
    {
        int ret = pthread_cancel(threadId_.getID());

        if (detached_)
        {
        }
        else
        {
            void *return_value;
            join(&return_value);
        }
    }
    catch (...)
    {
        std::cout << "System call error: pthread_cancel." << std::endl;
    }
}

int Thread::start(int stack_size)
{
    if (running_)
    {
        std::cout << "Try to start an already started thread." << std::endl;
        return FAILED;
    }

    pthread_t tid;
    if (stack_size > 0)
    {
        pthread_attr_t attr;
        int ret = pthread_attr_init(&attr);
        if (0 != ret)
        {
            std::cout << "System call error: pthread_attr_init." << std::endl;
            return FAILED;
        }

        if (stack_size < PTHREAD_STACK_MIN)
        {
            stack_size = PTHREAD_STACK_MIN;
        }

        ret = pthread_attr_setstacksize(&attr, stack_size);
        if (0 != ret)
        {
            std::cout << "System call error: pthread_attr_setstacksize." << std::endl;
            return FAILED;
        }

        ret = pthread_create(&tid, nullptr, startHook, this);
        if (0 != ret)
        {
            std::cout << "System call error: pthread_create." << std::endl;
            return FAILED;
        }
    }
    else
    {
        int ret = pthread_create(&tid, nullptr, startHook, this);
        if (0 != ret)
        {
            std::cout << "System call error: pthread_create." << std::endl;
            return FAILED;
        }
    }

    threadId_ = ThreadID(tid);
    running_ = true;

    return SUCCESS;
}

void *Thread::startHook(void *arg)
{
    Thread *pThread = static_cast<Thread *>(arg);
    pThread->run();
    pThread->done();
    return nullptr;
}

void Thread::done()
{
    running_ = false;
}

bool Thread::isAlive() const
{
    return running_;
}

const ThreadID &Thread::getID() const
{
    return threadId_;
}

int Thread::join(void **return_value) const
{
    if (detached_)
    {
        return FAILED;
    }

    int ret = pthread_join(threadId_.getID(), return_value);
    if (0 != ret)
    {
        std::cout << "System call error: pthread_join." << std::endl;
        return FAILED;
    }

    return SUCCESS;
}

int Thread::detach()
{
    if (detached_)
    {
        return SUCCESS;
    }

    int ret = pthread_detach(threadId_.getID());
    if (0 != ret)
    {
        std::cout << "System call error: pthread_detach." << std::endl;
        return FAILED;
    }

    detached_ = true;
    return SUCCESS;
}

void Thread::yield()
{
    int ret = sched_yield();
    if (ret < 0)
    {
        std::cout << "System call error: sched_yield." << std::endl;
    }
}

void Thread::sleep(int64_t seconds, int64_t useconds)
{
    timespec ts;
    memset(&ts, 0, sizeof(timespec));
    ts.tv_sec = seconds;
    ts.tv_nsec = useconds * 1000;
    int ret = nanosleep(&ts, 0);
    if (ret < 0)
    {
    }
}
