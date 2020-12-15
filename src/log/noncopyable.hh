#pragma once
class noncopyable
{
protected:
    noncopyable() {}
    virtual ~noncopyable() {}

private:
    // don't define these members
    noncopyable(const noncopyable &nc);
    noncopyable &operator=(const noncopyable &nc);
};
