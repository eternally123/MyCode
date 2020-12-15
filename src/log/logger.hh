#pragma once

#include <cstddef>
#include <stdarg.h>
#include <list>

#include "noncopyable.hh"
#include "logger_factory.hh"

class Appender;

class Logger : public noncopyable
{
    friend class LoggerFactory;

public:
    void perf(const char *fmt, ...);
    void fatal(const char *fmt, ...);
    void error(const char *fmt, ...);
    void warn(const char *fmt, ...);
    void info(const char *fmt, ...);
    void debug(
        const char *filename,
        int linenum,
        const char *function,
        const char *fmt, ...);
    void trace(const char *fmt, ...);

private:
    Logger(); // can't new
    virtual ~Logger();
    void setLevel(LogLevel level);
    void addAppender(Appender *apdr);
    void setName(const std::string &name);
    void doLog(
        LogLevel level,
        const char *fmt,
        va_list ap,
        const char *filename = NULL,
        int linenum = 0,
        const char *function = NULL);

private:
    LogLevel level_;                     // log level
    std::list<Appender *> appenderList_; // list of Appenders
    std::string name_;                   // Logger name
};
