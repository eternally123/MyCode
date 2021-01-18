#pragma once

class uncopyable
{
protected:
    uncopyable() {}
    virtual ~uncopyable() {}

private:
    uncopyable(const uncopyable &) = delete;
    uncopyable &operator=(const uncopyable &) = delete;
};