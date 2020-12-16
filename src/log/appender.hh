#pragma once

#include <cstddef>
#include <stdarg.h>
#include <string>

#include "loglevel.hh"
#include "noncopyable.hh"
#include "error.hh"

class Appender : public noncopyable
{
public:
    Appender();
    virtual ~Appender();

public:
    virtual inline int init();
    virtual void destroy();
    virtual void log(
        std::string loggerName,
        LogLevel level,
        const char *fmt,
        va_list ap,
        const char *filename = NULL,
        int linenum = 0,
        const char *function = NULL) = 0;

protected:
    std::string getTimeNow() const;
    std::string getPID() const;
    std::string getTID() const;
    std::string getPIDAndTID() const;
    std::string getLogLevelString(LogLevel level) const;
};

int Appender::init()
{
    return SUCCESSFUL;
}