#pragma once

#include <core/man/manager.hpp>

namespace Moon::Core
{
    template <class Type>
    Moon::Alias::ManagerType Manager_t<Type>::getManagerType()
    {
        static Moon::Alias::ManagerType type = ++nextType;
        return type;
    }
} // namespace Moon::Core
