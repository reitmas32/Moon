#pragma once

#include <core/sys/sys.hpp>

namespace Moon::Core
{
    template <MOON_IS_CTX_T... Type>
    Moon::Alias::SystemType System_t<Type...>::getSystemType() noexcept
    {
        static Moon::Alias::SystemType type = ++nextType;
        return type;
    }

    //-----------------------------------------------------
    //-----------------------------------------------------
    //-----------------------------------------------------

    template <typename Type>
    Moon::Alias::SystemType SystemVoid_t<Type>::getSystemType() noexcept
    {
        static Moon::Alias::SystemType type = ++nextType;
        return type;
    }
} // namespace Moon::Core