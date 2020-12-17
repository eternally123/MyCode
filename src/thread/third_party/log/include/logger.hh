#pragma once

#include <cstddef>
#include <stdarg.h>
#include <list>

#include <string>

#include "logger_factory.hh"

class Appender;

class Logger
{
    friend class LoggerFactory;

public:
    void perf(const char *fmt, ...); // 性能日志
    void fatal(const char *fmt, ...);
    void error(const char *fmt, ...);
    void warn(const char *fmt, ...);
    void info(const char *fmt, ...);
    void debug(
        const char *filename,
        int linenum,
        const char *function,
        const char *fmt, ...);
    void trace(const char *fmt, ...); // 跟踪日志

private:
    Logger();
    virtual ~Logger();
    Logger(const Logger &logger) = delete;
    Logger(Logger &&logger) = delete;

private:
    void setLevel(LogLevel level);
    void setName(const std::string &name);

private:
    void addAppender(Appender *apdr);
    void doLog(
        LogLevel level,
        const char *fmt,
        va_list ap,
        const char *filename = NULL,
        int linenum = 0,
        const char *function = NULL);

private:
    std::string name_;                   // Logger name
    LogLevel level_;                     // log level
    std::list<Appender *> appenderList_; // list of Appenders
};
