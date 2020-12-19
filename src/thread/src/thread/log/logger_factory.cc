#include <cstdio>
#include <cstdlib>
#include <utility>

#include "thread/log/logger.hh"
#include "thread/log/console_appender.hh"
#include "thread/log/syslog_appender.hh"

std::map<std::string, Logger *> LoggerFactory::loggerMap_;

LoggerFactory::LoggerFactory()
{
    // 初始化root logger
    Logger *rootLogger = new Logger();
    rootLogger->setName("ROOT");
#ifdef DEBUG
    rootLogger->setLevel(LogLevel::LOG_L_DEBUG);
#else
    rootLogger->setLevel(LogLevel::LOG_L_INFO);
#endif

    // 默认添加控制台日志输出
    Appender *p_Appender = new ConsoleAppender();
    if (0 != p_Appender->init())
    {
        fprintf(
            stderr,
            "Error occurred while initializing the ROOT logger. Program exited.\n");
        exit(1);
    }
    rootLogger->addAppender(p_Appender);

    auto resultpair = loggerMap_.insert(std::pair<std::string, Logger *>("ROOT", rootLogger));
    if (false == resultpair.second)
    {
    }
}

LoggerFactory::~LoggerFactory()
{
}

Logger *LoggerFactory::getRootLogger() const
{
    return loggerMap_["ROOT"];
}

void LoggerFactory::clear()
{
    if (!loggerMap_.empty())
    {
        for (auto it = loggerMap_.begin(); it != loggerMap_.end(); ++it)
        {
            delete it->second;
            it->second = NULL;
        }
    }
}
