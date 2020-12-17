#pragma once

#include <map>
#include <string>

#include "singleton.hh"
#include "loglevel.hh"

class Logger;

class LoggerFactory : public Singleton<LoggerFactory>
{
    friend class Singleton<LoggerFactory>;

public:
    Logger *getLogger(const std::string &loggerName);
    Logger *getRootLogger() const;
    void clear();

private:
    LoggerFactory(); // can't new
    LoggerFactory &operator=(const LoggerFactory &buffer);
    ~LoggerFactory();

private:
    static std::map<std::string, Logger *> loggerMap_; // map of logger
};
