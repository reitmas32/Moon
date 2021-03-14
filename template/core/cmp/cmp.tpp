#pragma once

#include <core/cmp/cmp.hpp>

#include <tools/moon_log.hpp>

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
      //TODO:Hacer los logs en el core del motor
      Moon::Tools::Moon_Log([&]() { spdlog::info("Delete Component_t wiht ComponentType {} and eid {}", this->getComponentType(), this->eid);});
    }

    template<class Type>
    Moon::Alias::ComponentType Component_t<Type>::getComponentType() noexcept
    {
        static Moon::Alias::ComponentType type = ++nextType;
        return type;
    }
} // namespace Moon::Core