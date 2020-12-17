#pragma once
#include "appender.hh"

class SyslogAppender : public Appender
{
public:
    SyslogAppender();
    ~SyslogAppender();

public:
    int init(void);
    void log(
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
