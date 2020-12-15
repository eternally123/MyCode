#include <cstdio>
#include <cstdlib>
#include <utility>

#include "logger.hh"
#include "console_appender.hh"
#include "syslog_appender.hh"

// logger map
std::map<std::string, Logger *> LoggerFactory::loggerMap_;

LoggerFactory::LoggerFactory()
{
    // init ROOT Logger
    Logger *rootLogger = new Logger();
    rootLogger->setName("ROOT");
#ifdef DEBUG
    rootLogger->setLevel(LOG_L_DEBUG);
#else
    rootLogger->setLevel(LOG_L_INFO);
#endif

    Appender *p_Appender;
    p_Appender = new ConsoleAppender();
    if (p_Appender->init() != 0)
    {
        fprintf(
            stderr,
            "Error occurred while initializing the ROOT logger. Program exited.\n");
        exit(1);
    }
    rootLogger->addAppender(p_Appender);

    std::pair<std::map<std::string, Logger *>::iterator, bool> logpair =
        loggerMap_.insert(
            std::pair<std::string, Logger *>(
                "ROOT", rootLogger));
    if (!logpair.second)
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
        for (std::map<std::string, Logger *>::iterator it = loggerMap_.begin();
             it != loggerMap_.end();
             ++it)
        {
            delete it->second;
            it->second = NULL;
        }
    }
}
