#pragma once

#include <core/man/manager.hpp>

namespace Moon::Core
{
    template <typename Type>
    Manager_t<Type>::Manager_t()
    {
    }

    template <typename Type>
    Manager_t<Type>::~Manager_t()
    {
    }

    template <class Type>
    Moon::Alias::ManagerType Manager_t<Type>::getManagerType()
    {
        static Moon::Alias::ManagerType type = ++nextType;
        return type;
    }
} // namespace Moon::Core
