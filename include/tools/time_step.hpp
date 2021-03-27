#pragma once

#include <iostream>
#include <thread>
#include <string>
#include <string_view>
#include <vector>

namespace Moon::Tools
{
    struct TimeStep_t
    {
        using clk = std::chrono::steady_clock;
        using nano_t = std::chrono::duration<std::uint64_t, std::nano>;
        using timepoint_t = std::chrono::time_point<clk, nano_t>;

        explicit TimeStep_t() noexcept
        {
            this->start();
        }

        void start() { m_start = clk::now(); }

        std::uint64_t ellapsed()
        {
            auto ns_passed{clk::now() - m_start};
            return ns_passed.count();
        }

        std::uint64_t waitUntil_ns(std::uint64_t to_ns)
        {
            if (ellapsed() < to_ns)
            {
                auto toWait{to_ns - ellapsed()};
                std::this_thread::sleep_for(nano_t{toWait});
                return toWait;
            }
            return 0;
        }

    private:
        timepoint_t m_start;
    };
    inline static std::vector<std::string> times;
    inline static auto timedCall = [](std::string name, auto &&func) {
        auto timer = Moon::Tools::TimeStep_t();
        func();
        std::cout<<"["<<name<<"] "<<timer.ellapsed() / 1000<<"ns \n";
    };
} // namespace Moon::Tools