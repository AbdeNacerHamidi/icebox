#define FDP_MODULE "log"
#include "log.hpp"

#include <loguru.hpp>

#include <cstdarg>
#include <cstdio>

void logg::init(int argc, char** argv)
{
    loguru::g_preamble_uptime = false;
    loguru::g_preamble_date   = false;
    loguru::g_preamble_thread = false;
    loguru::g_preamble_file   = false;
    loguru::init(argc, argv);
}

#ifdef _MSC_VER
#    define FMT_VSNPRINTF vsprintf_s
#else
#    define FMT_VSNPRINTF vsnprintf
#endif

void logg::print(logg::level_t level, const char* fmt, ...)
{
    char    buffer[4096];
    va_list args;
    va_start(args, fmt);
    FMT_VSNPRINTF(buffer, sizeof buffer, fmt, args);
    va_end(args);
    switch(level)
    {
        case level_t::info:
            LOG_F(INFO, "%s", buffer);
            return;

        case level_t::error:
            LOG_F(ERROR, "%s", buffer);
            return;
    }
}
