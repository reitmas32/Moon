#pragma once

#include <core/ent/ent_base.hpp>

namespace Moon::Core {

    template<class CMP_t>
    requires std::is_base_of<Moon::Core::ComponentBase_t, CMP_t>::value void
    EntityBase_t::addComponent(CMP_t* cmp)
    {
        this->components.insert({ CMP_t::getComponentType(), cmp });
        Moon::Tools::Moon_Log([&]() { spdlog::info("addComponent wiht ComponentType {} and eid {}", cmp->getComponentType(), cmp->eid); });
    }

    template<class CMP_t>
    requires std::is_base_of<Moon::Core::ComponentBase_t, CMP_t>::value CMP_t*
    EntityBase_t::getComponent()
    {
        auto i = components.find(CMP_t::getComponentType());

        if (i != components.end()) {
            return static_cast<CMP_t*>(i->second);
        }

        return nullptr;
    }
} // namespace Moon::Core