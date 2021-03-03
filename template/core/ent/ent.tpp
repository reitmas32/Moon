#pragma once

#include "../../../include/core/ent/ent.hpp"

namespace Moon::Core {
    template<class Type>
    Entity_t<Type>::Entity_t()
    {}

    template<class Type>
    Entity_t<Type>::Entity_t(Moon::Alias::EntityId eid)
      : eid{ eid }
    {}

    template<class Type>
    Entity_t<Type>::~Entity_t()
    {
        /*Nada*/
    }

    template<class Type>
    Moon::Alias::EntityType Entity_t<Type>::getEntityType() noexcept
    {
        static Moon::Alias::EntityType type = ++nextType;
        return type;
    }
} // namespace Moon::Core