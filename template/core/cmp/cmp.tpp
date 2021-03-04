#pragma once

#include <core/cmp/cmp.hpp>

namespace Moon::Core {
    template<class Type>
    Component_t<Type>::Component_t()
    {}

    template<class Type>
    Component_t<Type>::Component_t(Moon::Alias::EntityId eid)
    {
      this->eid = eid;
    }

    template<class Type>
    Component_t<Type>::~Component_t()
    { /*Nada*/
    }

    template<class Type>
    Moon::Alias::ComponentType Component_t<Type>::getComponentType() noexcept
    {
        static Moon::Alias::ComponentType type = ++nextType;
        return type;
    }
} // namespace Moon::Core