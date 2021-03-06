#ifndef ASTRA_LOGGER_H
#define ASTRA_LOGGER_H

#include <Astra/astra_types.h>
#include "astra_logging.hpp"
#include <string>

#if defined(_MSC_VER)  // Visual C++
#   define LOG_FUNC __FUNCSIG__
#elif defined(__GNUC__)  // GCC
#   define LOG_FUNC __PRETTY_FUNCTION__
#elif defined(__INTEL_COMPILER)  // Intel C++
#   define LOG_FUNC __PRETTY_FUNCTION__
#elif defined(__clang__)  // Clang++
#   define LOG_FUNC __PRETTY_FUNCTION__
#else
#   if defined(__func__)
#      define LOG_FUNC __func__
#   else
#      define LOG_FUNC ""
#   endif  // defined(__func__)
#endif  // defined(_MSC_VER)

#define LOG_TRACE(channel, format, ...) \
    ::astra::log(channel, ASTRA_SEVERITY_TRACE, __FILE__, __LINE__, LOG_FUNC, format , ##__VA_ARGS__)

#define LOG_INFO(channel, format, ...) \
    ::astra::log(channel, ASTRA_SEVERITY_INFO, __FILE__, __LINE__, LOG_FUNC, format , ##__VA_ARGS__)

#define LOG_DEBUG(channel, format, ...) \
    ::astra::log(channel, ASTRA_SEVERITY_DEBUG, __FILE__, __LINE__, LOG_FUNC, format , ##__VA_ARGS__)

#define LOG_ERROR(channel, format, ...) \
    ::astra::log(channel, ASTRA_SEVERITY_ERROR, __FILE__, __LINE__, LOG_FUNC, format , ##__VA_ARGS__)

#define LOG_FATAL(channel, format, ...) \
    ::astra::log(channel, ASTRA_SEVERITY_FATAL, __FILE__, __LINE__, LOG_FUNC, format , ##__VA_ARGS__)

#define LOG_WARN(channel, format, ...) \
    ::astra::log(channel, ASTRA_SEVERITY_WARN, __FILE__, __LINE__, LOG_FUNC, format , ##__VA_ARGS__)

namespace astra {

    void log(const char* channel,
             astra_log_severity_t logLevel,
             const char* fileName,
             int lineNo,
             const char* func,
             const char* format, ...);


    void log_vargs(const char* channel,
                   astra_log_severity_t logLevel,
                   const char* fileName,
                   int lineNo,
                   const char* func,
                   const char* format,
                   va_list args);

    inline void log_nyan()
    {
        LOG_INFO("Nyan", "+      o     +              o");
        LOG_INFO("Nyan", "    +             o      +       +");
        LOG_INFO("Nyan", "o          +");
        LOG_INFO("Nyan", "    o  +           +        +");
        LOG_INFO("Nyan", "+        o     o       +        o");
        LOG_INFO("Nyan", "-_-_-_-_-_-_-_,------,      o");
        LOG_INFO("Nyan", "_-_-_-_-_-_-_-|   /\\_/\\");
        LOG_INFO("Nyan", "-_-_-_-_-_-_-~|__( ^ .^)  +     +");
        LOG_INFO("Nyan", "_-_-_-_-_-_-_-\"\"  \"\"");
        LOG_INFO("Nyan", "+      o         o   +       o");
        LOG_INFO("Nyan", "    +         +");
        LOG_INFO("Nyan", "o        o         o      o     +");
        LOG_INFO("Nyan", "    o           +");
        LOG_INFO("Nyan", "+      +     o        o      +");
    }
}

#endif /* ASTRA_LOGGER_H */
