#pragma once

#include <string>

enum class LogLevel : int
{
    LOG_L_TRACE = 0,
    LOG_L_DEBUG = 1,
    LOG_L_INFO = 2,
    LOG_L_WARN = 3,
    LOG_L_ERROR = 4,
    LOG_L_FATAL = 5,
    LOG_L_PERF = 6,
    LOG_L_NOLOG = 100 // 不记录任何日志
};

class LogLevelString
{
public:
    static std::string getLogLevelStr(LogLevel level);
};
