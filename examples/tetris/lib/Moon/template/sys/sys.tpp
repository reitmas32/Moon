#pragma once

#include "../../include/sys/sys.hpp"

namespace Moon::Core {
    template<Moon::Concepts::Ctx_t... Type>
    System_t<Type...>::System_t()
    {}

    template<Moon::Concepts::Ctx_t... Type>
    System_t<Type...>::~System_t()
    {
        /*Nada*/
    }

    template<Moon::Concepts::Ctx_t... Type>
    Moon::Alias::SystemType System_t<Type...>::getSystemType() noexcept
    {
        static Moon::Alias::SystemType type = ++nextType;
        return type;
    }
} // namespace Moon::Core