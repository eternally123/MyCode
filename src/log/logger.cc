#include <cstdarg>

#include "appender.hh"
#include "logger.hh"

Logger::Logger()
    : level_(LOG_L_DEBUG)
{
}

Logger::~Logger()
{
    try
    {
        // 析构每个Appender
        for (std::list<Appender *>::iterator it = appenderList_.begin();
             it != appenderList_.end();)
        {
            std::list<Appender *>::iterator tmpit = it;
            ++it;
            delete (*tmpit);
            *tmpit = NULL;
        }
        appenderList_.clear();
    }
    catch (...)
    {
    }
}

void Logger::setLevel(LogLevel level)
{
    level_ = level;
}

void Logger::setName(const std::string &name)
{
    name_ = name;
}

void Logger::addAppender(Appender *apdr)
{
    appenderList_.push_back(apdr);
}

void Logger::doLog(
    LogLevel level,
    const char *fmt,
    va_list ap,
    const char *filename,
    int linenum,
    const char *function)
{
    // 把日志写入到每个Appender
    for (std::list<Appender *>::iterator it = appenderList_.begin();
         it != appenderList_.end();
         ++it)
    {
        if (level == LOG_L_DEBUG) // 如果是调试信息
        {
            if (NULL == filename || NULL == function)
            {
                (*it)->log(name_, level, fmt, ap, "NULL", linenum, "NULL");
            }
            else
            {
                (*it)->log(name_, level, fmt, ap, filename, linenum, function);
            }
        }
        else
        {
            (*it)->log(name_, level, fmt, ap);
        }
    }
}

void Logger::perf(const char *fmt, ...)
{
    // 如果设定的日志级别比FATAL低，则记录日志
    if (LOG_L_PERF >= level_)
    {
        va_list ap;

        va_start(ap, fmt);
        doLog(LOG_L_PERF, fmt, ap);
        va_end(ap);
    }
}

void Logger::fatal(const char *fmt, ...)
{
    // 如果设定的日志级别比FATAL低，则记录日志
    if (LOG_L_FATAL >= level_)
    {
        va_list ap;

        va_start(ap, fmt);
        doLog(LOG_L_FATAL, fmt, ap);
        va_end(ap);
    }
}

void Logger::error(const char *fmt, ...)
{
    if (LOG_L_ERROR >= level_)
    {
        va_list ap;

        va_start(ap, fmt);
        doLog(LOG_L_ERROR, fmt, ap);
        va_end(ap);
    }
}

void Logger::warn(const char *fmt, ...)
{
    if (LOG_L_WARN >= level_)
    {
        va_list ap;

        va_start(ap, fmt);
        doLog(LOG_L_WARN, fmt, ap);
        va_end(ap);
    }
}

void Logger::info(const char *fmt, ...)
{

    if (LOG_L_INFO >= level_)
    {
        va_list ap;

        va_start(ap, fmt);
        doLog(LOG_L_INFO, fmt, ap);
        va_end(ap);
    }
}

void Logger::debug(
    const char *filename,
    int linenum,
    const char *function,
    const char *fmt, ...)
{
    if (LOG_L_DEBUG >= level_)
    {
        va_list ap;

        va_start(ap, fmt);
        doLog(LOG_L_DEBUG, fmt, ap, filename, linenum, function);
        va_end(ap);
    }
}

void Logger::trace(const char *fmt, ...)
{
    if (LOG_L_TRACE >= level_)
    {
        va_list ap;

        va_start(ap, fmt);
        doLog(LOG_L_TRACE, fmt, ap);
        va_end(ap);
    }
}
