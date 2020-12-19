#pragma once

#include <cstddef>
#include <pthread.h>

template <typename T>
class Singleton
{
public:
    virtual ~Singleton() {}
    static T *getInstance()
    {
        //pthread_once make the initInstance only use once by value instance_initFlag_;
        pthread_once(&instance_initFlag_, &Singleton::initInstance);
        return pInstance_;
    }

    static void destroyInstance()
    {
        pthread_once(&instance_deleteFlag_, &Singleton::deleteInstance);
    }

protected:
    // can't new
    Singleton() {}

private:
    static pthread_once_t instance_initFlag_; // to protect pInstance_
    static pthread_once_t instance_deleteFlag_;
    static T *pInstance_; // singleton

private:
    // can't copy
    Singleton(const Singleton &s);
    Singleton &operator=(const Singleton &s);

    // init pInstance_
    static void initInstance()
    {
        pInstance_ = new T();
    }
    static void deleteInstance()
    {
        if (pInstance_ != NULL)
        {
            delete pInstance_;
            pInstance_ = NULL;
        }
    }
};

template <typename T>
pthread_once_t Singleton<T>::instance_initFlag_ = PTHREAD_ONCE_INIT;

template <typename T>
pthread_once_t Singleton<T>::instance_deleteFlag_ = PTHREAD_ONCE_INIT;

template <typename T>
T *Singleton<T>::pInstance_ = NULL;
