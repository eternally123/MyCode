#pragma once
#include <cstdarg>

#include "appender.hh"

class ConsoleAppender : public Appender
{
public:
    ConsoleAppender();
    virtual ~ConsoleAppender();

public:
    virtual void log(
        std::string loggerName,
        LogLevel level,
        const char *fmt,
        va_list ap,
        const char *filename = NULL,
        int linenum = 0,
        const char *function = NULL);

private:
    uint32_t logbuffersize_;
};