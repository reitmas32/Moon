#pragma once

#include "../../include/ent/ent_base.hpp"

namespace Moon::Core
{

    template <typename CMP_t>
    void EntityBase_t::addComponent(CMP_t *cmp)
    {
        this->components.insert({CMP_t::getComponentType(), cmp});
    }

    template <typename CMP_t>
    CMP_t *EntityBase_t::getComponent()
    {
        auto i = components.find(CMP_t::getComponentType());

        if (i != components.end())
        {
            return static_cast<CMP_t *>(i->second);
        }

        return nullptr;
    }
} // namespace Moon::Core