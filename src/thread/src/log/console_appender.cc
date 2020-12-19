#include <cstdio>
#include <cstring>
#include <inttypes.h>

#include "console_appender.hh"

ConsoleAppender::ConsoleAppender()
    : logbuffersize_(1000)
{
}

ConsoleAppender::~ConsoleAppender()
{
}

void ConsoleAppender::log(
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
    buffer[len] = '\0';

    // 输出到stderr
    fprintf(stderr, "%s", buffer);
}
