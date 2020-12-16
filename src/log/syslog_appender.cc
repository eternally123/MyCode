
#include <string.h>
#include <syslog.h>
#include <stdio.h>
#include <iostream>
#include <inttypes.h>

#include "syslog_appender.hh"

SyslogAppender::SyslogAppender()
    : logbuffersize_(1000)
{
}

SyslogAppender::~SyslogAppender()
{
    closelog();
}

int SyslogAppender::init()
{
    openlog(NULL, LOG_PID, LOG_USER);
    return SUCCESSFUL;
}

void SyslogAppender::log(
    std::string loggerName,
    LogLevel level,
    const char *fmt,
    va_list ap,
    const char *filename,
    int linenum,
    const char *function)
{
    char buffer[logbuffersize_];

    // 时间、日志级别、进程ID线程ID
    int rt = snprintf(buffer, logbuffersize_, "%s %s %s ",
                      getTimeNow().c_str(),
                      getLogLevelString(level).c_str(),
                      getPIDAndTID().c_str());
    if (rt < 0)
    {
    }

    // 调试日志
    size_t len = strlen(buffer);

    if (level == LogLevel::LOG_L_DEBUG && filename != NULL && linenum != 0 && function != NULL)
    {
        rt = snprintf(buffer + len, logbuffersize_ - len,
                      "(FILE:%s, LINE:%d, FUNC:%s) : ",
                      filename, linenum, function);
        if (rt < 0)
        {
        }
    }

    // 其他日志
    len = strlen(buffer);
    rt = vsnprintf(buffer + len, logbuffersize_ - len, fmt, ap);
    if (rt < 0)
    {
    }

    len = strlen(buffer);
    // 添加换行
    buffer[len++] = '\n';
    buffer[len++] = '\0';

    switch (level)
    {
    case LogLevel::LOG_L_TRACE:
    case LogLevel::LOG_L_DEBUG:
        ::syslog(LOG_USER | LOG_DEBUG, "%s", buffer);
        break;
    case LogLevel::LOG_L_INFO:
        ::syslog(LOG_USER | LOG_INFO, "%s", buffer);
        break;
    case LogLevel::LOG_L_WARN:
        ::syslog(LOG_USER | LOG_WARNING, "%s", buffer);
        break;
    case LogLevel::LOG_L_ERROR:
        ::syslog(LOG_USER | LOG_ERR, "%s", buffer);
        break;
    case LogLevel::LOG_L_FATAL:
        ::syslog(LOG_USER | LOG_EMERG, "%s", buffer);
        break;
    case LogLevel::LOG_L_PERF:
        ::syslog(LOG_LOCAL0 | LOG_INFO, "%s", buffer);
        break;
    default:
        std::cerr << "UNKNOWN LOG LEVEL" << std::endl;
        break;
    }
    return;
}
