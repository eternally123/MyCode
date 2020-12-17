#pragma once

class nocopyable
{

protected:
    nocopyable() {}
    virtual ~nocopyable() {}

private:
    nocopyable(const nocopyable &n) = delete;
    nocopyable &operator=(const nocopyable &n) = delete;
};

class nomoveable
{
protected:
    nomoveable() {}
    virtual ~nomoveable() {}

private:
    nomoveable(const nomoveable &&n) = delete;
    nomoveable &operator=(const nomoveable &&n) = delete;
};