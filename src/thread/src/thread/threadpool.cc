#include "thread/threadpool.hh"
#include "thread/log/log.hh"
#include "thread/types.hh"

#include <unistd.h>

ThreadPool::ThreadPool(int thread_num)
    : thread_num_(thread_num)
{
}

ThreadPool::~ThreadPool()
{
}

int ThreadPool::start()
{
    int ret = init();
    if (0 != ret)
    {
        return FAILED;
    }

    for (int i = 0; i < thread_num_; i++)
    {
        WorkThread *wt = new WorkThread(read_handle_);
        wt->start();
        INFO_LOG("thread run");
        workThreadvec_.push_back(wt);
    }

    return SUCCESS;
}

int ThreadPool::addTask(BaseTask *task)
{
    int ret = write(write_handle_, static_cast<void *>(&task), 8);
    if (8 != ret)
    {
        ERROR_LOG("error");
        return FAILED;
    }
    return SUCCESS;
}

int ThreadPool::init()
{
    int fd[2];
    int ret = pipe(fd);
    if (0 != ret)
    {
        ERROR_LOG("Syscall Error: pipe.");
        return FAILED;
    }
    read_handle_ = fd[0];
    write_handle_ = fd[1];
    return SUCCESS;
}

ThreadPool::WorkThread::WorkThread(int readfd)
    : readfd_(readfd)
{
}

void ThreadPool::WorkThread::run()
{
    BaseTask *bt = nullptr;
    while (1)
    {
        int ret = read(readfd_, &bt, 8);
        INFO_LOG("readfd=%d", readfd_);
        if (ret < 0)
        {
            int err = errno;
            ERROR_LOG("Syscall Error. read. %d ", err);
            continue;
        }
        else
        {
            INFO_LOG("task arrive,%p", bt);
            bt->run();
            INFO_LOG("task finish");
        }
    }
}

BaseTask::BaseTask(std::function<void()> f)
    : task_(f)
{
}

BaseTask::~BaseTask()
{
}

void BaseTask::run()
{
    task_();
}