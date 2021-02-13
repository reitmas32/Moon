#pragma once

#include "../../include/cmp/cmp.hpp"

namespace Moon::Core
{
    template <class Type>
    Component_t<Type>::Component_t() {}

    template <class Type>
    Component_t<Type>::Component_t(Moon::Alias::EntityId eid) : eid{eid} {}

    template <class Type>
    Component_t<Type>::~Component_t()
    {
        /*Nada*/
    }

    template <class Type>
    Moon::Alias::ComponentType Component_t<Type>::getComponentType()
    {
        static Moon::Alias::ComponentType type = ++nextType;
        return type;
    }
} // namespace Moon::Core