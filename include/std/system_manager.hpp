#pragma once

#include <stack>
#include <memory>

#include <core/man/manager.tpp>
#include <core/sys/sys_base.hpp>

namespace Moon::Tools
{
    struct SystemManager_t : public Moon::Core::Manager_t<SystemManager_t>
    {
        explicit SystemManager_t() = default;

        template <typename Sys_t, typename... Ts>
        void addSystem(Ts &&... args)
        {
            static_assert(std::is_base_of<Moon::Core::SystemBase_t, Sys_t>::value, "EROOR! Invalid System");
            this->systems.insert({Sys_t::getSystemType(), std::make_unique<Sys_t>(std::forward<decltype(args)>(args)...)});
        }

        template <typename Sys_t>
        Sys_t *getSystem()
        {
            static_assert(std::is_base_of<Moon::Core::SystemBase_t, Sys_t>::value, "EROOR! Invalid System");
            auto it = this->systems.find(Sys_t::getSystemType());
            if (it != this->systems.end())
            {
                return static_cast<Sys_t *>(it->second.get());
            }
            return nullptr;
        }

        bool alive()
        {
            for (auto &sys : this->systems)
            {
                if (sys.second->alive())
                {
                    return true;
                }
            }
            return false;
        }

    private:
        std::unordered_map<Moon::Alias::SystemType, std::unique_ptr<Moon::Core::SystemBase_t>> systems;
    };

} // namespace Moon::GLFW