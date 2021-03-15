#pragma once

#include <core/sys/sys.hpp>

namespace Moon::Core
{
    template <Moon::Concepts::Ctx_t... Type>
    System_t<Type...>::System_t()
    {
        Moon::Tools::Moon_Log([&]() { spdlog::info("Create System_t wiht SystemType {}", this->getSystemType()); });
    }

    template <Moon::Concepts::Ctx_t... Type>
    System_t<Type...>::~System_t()
    {
        Moon::Tools::Moon_Log([&]() { spdlog::info("Delete System_t wiht SystemType {}", this->getSystemType()); });
    }

    template <Moon::Concepts::Ctx_t... Type>
    Moon::Alias::SystemType System_t<Type...>::getSystemType() noexcept
    {
        static Moon::Alias::SystemType type = ++nextType;
        return type;
    }

    //-----------------------------------------------------
    //-----------------------------------------------------
    //-----------------------------------------------------

    template <typename Type>
    SystemVoid_t<Type>::SystemVoid_t()
    {
        Moon::Tools::Moon_Log([&]() { spdlog::info("Create SystemVoid_t wiht SystemType {}", this->getSystemType()); });
    }

    template <typename Type>
    SystemVoid_t<Type>::~SystemVoid_t()
    {
        Moon::Tools::Moon_Log([&]() { spdlog::info("Delete SystemVoid_t wiht SystemType {}", this->getSystemType()); });
    }

    template <typename Type>
    Moon::Alias::SystemType SystemVoid_t<Type>::getSystemType() noexcept
    {
        static Moon::Alias::SystemType type = ++nextType;
        return type;
    }
} // namespace Moon::Core