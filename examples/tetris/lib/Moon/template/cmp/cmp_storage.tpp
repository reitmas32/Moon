#pragma once

#include "../../include/cmp/cmp_storage.hpp"

#define NUM_CMPS 100

namespace Moon::Core {
    ComponentStorage_t::ComponentStorage_t() {}

    template<Moon::Concepts::Cmp_t CMP_t, typename... Ts>
    CMP_t& ComponentStorage_t::createComponent(Moon::Alias::EntityId eid,
                                               Ts&&... args)
    {
        auto& v = this->getComponents<CMP_t>();
        auto& cmp = v.emplace_back(eid, args...);
        return cmp;
    }

    template<Moon::Concepts::Cmp_t CMP_t>
    std::vector<CMP_t>& ComponentStorage_t::createComponentVector()
    {
        auto v = std::make_unique<Moon::Core::ComponentVect_t<CMP_t>>();
        v->components.reserve(NUM_CMPS);
        auto typeID = CMP_t::getComponentType();
        auto* vectCmp = v.get();
        this->storage[typeID] = std::move(v);
        return vectCmp->components;
    }

    template<Moon::Concepts::Cmp_t CMP_t>
    std::vector<CMP_t>& ComponentStorage_t::getComponents()
    {
        auto typeID = CMP_t::getComponentType();
        auto it = this->storage.find(typeID);
        if (it != this->storage.end()) {
            auto* comVect = dynamic_cast<Moon::Core::ComponentVect_t<CMP_t>*>(
              it->second.get());
            return comVect->components;
        } else {
            return this->createComponentVector<CMP_t>();
        }
    }

    template<Moon::Concepts::Cmp_t CMP_t>
    const std::vector<CMP_t>& ComponentStorage_t::getComponents() const
    {
        auto typeID = CMP_t::getComponentType();
        auto it = this->storage.find(typeID);
        if (it != this->storage.end()) {
            auto* comVect = dynamic_cast<Moon::Core::ComponentVect_t<CMP_t>*>(
              it->second.get());
            return comVect->components;
        } else {
            throw "Asi no por favor !!!";
        }
    }
} // namespace Moon::Core