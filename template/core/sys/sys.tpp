#pragma once

#include <core/sys/sys.hpp>

namespace Moon::Core
{
    template <Moon::Concepts::Ctx_t... Type>
    System_t<Type...>::System_t()
    {
    }

    template <Moon::Concepts::Ctx_t... Type>
    System_t<Type...>::~System_t()
    {
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
    }

    template <typename Type>
    SystemVoid_t<Type>::~SystemVoid_t()
    {
    }

    template <typename Type>
    Moon::Alias::SystemType SystemVoid_t<Type>::getSystemType() noexcept
    {
        static Moon::Alias::SystemType type = ++nextType;
        return type;
    }
} // namespace Moon::Core