#pragma once

#ifndef RELEASE
#include <include/termcolor.hpp>
#endif

#include <thread>
#include <chrono>
#include <ctime>

namespace Moon::Tools::Logs
{
//TODO: México
#ifndef RELEASE
    inline static constexpr std::int8_t locale{6};
#endif
    using clk = std::chrono::steady_clock;
    using nano_t = std::chrono::duration<std::uint64_t, std::nano>;
    using timepoint_t = std::chrono::time_point<clk, nano_t>;

    inline void printTime()
    {
        std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
        auto duration = now.time_since_epoch();
        typedef std::chrono::duration<int, std::ratio_multiply<std::chrono::hours::period, std::ratio<locale>>::type> Days; /* UTC: +8:00 */

        Days days = std::chrono::duration_cast<Days>(duration);
        duration -= days;
        auto hours = std::chrono::duration_cast<std::chrono::hours>(duration);
        duration -= hours;
        auto minutes = std::chrono::duration_cast<std::chrono::minutes>(duration);
        duration -= minutes;
        auto seconds = std::chrono::duration_cast<std::chrono::seconds>(duration);
        duration -= seconds;
        auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(duration);
        duration -= milliseconds;
        auto microseconds = std::chrono::duration_cast<std::chrono::microseconds>(duration);
        duration -= microseconds;
        auto nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(duration);

        std::cout << "[ ";
        std::cout << hours.count() << ":"
                  << minutes.count() << ":"
                  << seconds.count() << ":"
                  << milliseconds.count() << ":"
                  << microseconds.count() << ":"
                  << nanoseconds.count() << " ] ";
    }

    template <typename... Args>
    void contructor(std::string_view name, void *location, Args &&...args)
    {
#ifndef RELEASE
        printTime();
        if (location == nullptr)
        {
            std::cout << termcolor::red << termcolor::bold << termcolor::blink << "Contructor Error Segmentation fault"
                      << termcolor::reset << " in " << name << std::endl;
            return;
        }
        std::cout << termcolor::green << termcolor::bold << "Contructor"
                  << termcolor::reset << " of "
                  << termcolor::blue
                  << name << termcolor::reset
                  << " in " << termcolor::yellow << location << termcolor::reset;
        ((std::cout << std::forward<Args>(args)), ...);
        std::cout << std::endl;
#endif
    }

    template <typename... Args>
    void destructor(std::string_view name, void *location, Args &&...args)
    {
#ifndef RELEASE
        printTime();
        if (location == nullptr)
        {
            std::cout << termcolor::red << termcolor::bold << termcolor::blink << "Destructor Error Segmentation fault"
                      << termcolor::reset << " in " << name << std::endl;
            return;
        }
        std::cout << termcolor::red << termcolor::bold << "Destructor"
                  << termcolor::reset << " of "
                  << termcolor::blue
                  << name << termcolor::reset
                  << " in " << termcolor::yellow << location << termcolor::reset;
        ((std::cout << std::forward<Args>(args)), ...);
        std::cout << std::endl;
#endif
    }

    template <typename... Args>
    void error(std::string_view message, Args &&...args)
    {
#ifndef RELEASE
        printTime();
        std::cout << termcolor::red << termcolor::bold << "Error"
                  << termcolor::reset << " { "
                  << termcolor::red
                  << message << termcolor::reset
                  << " } " << termcolor::reset;
        ((std::cout << std::forward<Args>(args)), ...);
        std::cout << std::endl;
#endif
    }

} // namespace Moon::Tools
