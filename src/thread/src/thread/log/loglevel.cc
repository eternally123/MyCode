#include "thread/log/loglevel.hh"

std::string LogLevelString::getLogLevelStr(LogLevel level)
{
    switch (level)
    {
    case LogLevel::LOG_L_TRACE:
        return std::string("TRACE");
        break;
    case LogLevel::LOG_L_DEBUG:
        return std::string("DEBUG");
        break;
    case LogLevel::LOG_L_INFO:
        return std::string("INFO");
        break;
    case LogLevel::LOG_L_WARN:
        return std::string("WARN");
        break;
    case LogLevel::LOG_L_ERROR:
        return std::string("ERROR");
        break;
    case LogLevel::LOG_L_FATAL:
        return std::string("FATAL");
        break;
    case LogLevel::LOG_L_PERF:
        return std::string("PERF");
        break;
    case LogLevel::LOG_L_NOLOG:
        return std::string("NO");
        break;
    default:
        return std::string("");
        break;
    }
}