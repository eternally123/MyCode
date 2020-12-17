#pragma once

#include <cstring>
#include <cerrno>

#include "logger.hh"

#define TRACE_LOG(_fmt_, args...) LoggerFactory::getInstance()->getRootLogger()->trace(_fmt_, ##args)

#define DEBUG_LOG(_fmt_, args...) LoggerFactory::getInstance()->getRootLogger()->debug(__FILE__, __LINE__, __FUNCTION__, _fmt_, ##args)

#define INFO_LOG(_fmt_, args...) LoggerFactory::getInstance()->getRootLogger()->info(_fmt_, ##args)

#define WARN_LOG(_fmt_, args...) LoggerFactory::getInstance()->getRootLogger()->warn(_fmt_, ##args)

#define ERROR_LOG(_fmt_, args...) LoggerFactory::getInstance()->getRootLogger()->error(_fmt_, ##args)

#define FATAL_LOG(_fmt_, args...) LoggerFactory::getInstance()->getRootLogger()->fatal(_fmt_, ##args)

#define PERF_LOG(_fmt_, args...) LoggerFactory::getInstance()->getRootLogger()->perf(_fmt_, ##args)
