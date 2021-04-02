#pragma once

//#include <spdlog/spdlog.h>
//#include <spdlog/cfg/env.h>
#include <functional>
namespace Moon::Tools
{
    inline void Moon_Log(std::function<void()> log)
    {
#if not defined(RELEASE)
        log();
#endif
    }
    inline void Moon_Log()
    {
#if not defined(RELEASE)
        //log();
#endif
    }

} // namespace Moon::Tools
