#pragma once
#include "thread/thread.hh"
#include "thread/utils/class_constructor.hh"

#include <vector>
#include <functional>
/**
 * 线程池，主要由工作线程组成
 * 通过管道（工作队列）进行任务发放
 **/
class BaseTask;

class ThreadPool : public nocopyable, public nomoveable
{
protected:
    class WorkThread : public Thread
    {
    public:
        WorkThread(int readfd);
        virtual void run() override;

    private:
        int readfd_;
    };
    using WorkThreadVec = std::vector<WorkThread *>;

public:
    ThreadPool(int thread_num = 2);
    ~ThreadPool();

public:
    int start();
    int stop();
    int addTask(BaseTask *task);

private:
    int init();

private:
    int read_handle_;
    int write_handle_;
    int thread_num_;
    int status_; // 0 for stop 1 for run
    WorkThreadVec workThreadvec_;
};

/**
 * 任务类，需要将任务封装到此类中，丢给线程池运行
 **/
class BaseTask
{
    friend class ThreadPool;

public:
    BaseTask();
    virtual ~BaseTask();

protected:
    virtual void job(){};

private:
    void run();
};