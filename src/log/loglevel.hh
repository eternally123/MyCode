#pragma once

enum _LogLevel
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

typedef _LogLevel LogLevel;

// 日志级别的字符串表示
#define LOG_L_PERF_STR "PERF"
#define LOG_L_FATAL_STR "FATAL"
#define LOG_L_ERROR_STR "ERROR"
#define LOG_L_WARN_STR "WARN "
#define LOG_L_INFO_STR "INFO "
#define LOG_L_DEBUG_STR "DEBUG"
#define LOG_L_TRACE_STR "TRACE"

// 日志级别字串数组，可以使用Level来索引
static const char *LOG_LEVEL_STR[] __attribute__((unused)) =
    {
        LOG_L_TRACE_STR,
        LOG_L_DEBUG_STR,
        LOG_L_INFO_STR,
        LOG_L_WARN_STR,
        LOG_L_ERROR_STR,
        LOG_L_FATAL_STR,
        LOG_L_PERF_STR};
