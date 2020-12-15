#pragma once

#include <pthread.h>

class ThreadID
{
public:
    ThreadID(){};
    ThreadID(const pthread_t &tid);
    ThreadID(const ThreadID &tid);
    ThreadID(ThreadID &&) = delete;
    ~ThreadID(){};

public:
    ThreadID &operator=(const ThreadID &tid);
    bool operator==(const ThreadID &tid);
    bool operator!=(const ThreadID &tid);

public:
    pthread_t getID() const;

private:
    pthread_t tid_;
};

/*
    description:
        线程类，不支持拷贝构造和移动构造
        支持detach、join、
        支持sleep、yield
*/
class Thread
{
public:
    Thread();
    Thread(const Thread &thread) = delete;
    Thread(Thread &&thread) = delete;
    virtual ~Thread();

public:
    // start isAlive join detach id
    int start(int stack_size = 0);
    bool isAlive() const;
    int join(void **return_value) const;
    int detach();
    const ThreadID &getID() const;
    // void pushCleanupFunc(void (*return_func)(void *), void *arg);

protected:
    virtual void run() = 0;
    void yield();
    void sleep(int64_t seconds, int64_t useconds); // 类型是否平台无关？
    // void popCleanupFunc(int execute);

private:
    static void *startHook(void *arg);
    void done();

public:
    bool running_;
    bool detached_;
    ThreadID threadId_;
};