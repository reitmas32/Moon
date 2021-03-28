#pragma once

#include <core/cmp/cmp_storage.hpp>

#include <core/cmp/cmp_vect.tpp>

#define NUM_CMPS 100

namespace Moon::Core
{
    ComponentStorage_t::ComponentStorage_t()
    {
        Moon::Tools::Moon_Log([&]() { spdlog::info("Create ComponentStorage_t in location {:p}", (void *)this); });
    }

    template <Moon::Concepts::Cmp_t CMP_t, typename... Ts>
    CMP_t &ComponentStorage_t::createComponent(Moon::Alias::EntityId eid,
                                               Ts &&...args)
    {
        auto &v = this->getComponents<CMP_t>();
        auto &cmp = v.emplace_back(eid, args...);
        Moon::Tools::Moon_Log([&]() { spdlog::info("Pos-Create Component wiht ComponentType {} and eid {} in location {:p}", CMP_t::getComponentType(), eid, (void*)&cmp); });
        return cmp;
    }

    template <Moon::Concepts::Cmp_t CMP_t>
    std::vector<CMP_t> &ComponentStorage_t::createComponentVector()
    {
        auto v = std::make_unique<Moon::Core::ComponentVect_t<CMP_t>>();
        v->components.reserve(NUM_CMPS);
        auto typeID = CMP_t::getComponentType();
        auto *vectCmp = v.get();
        Moon::Tools::Moon_Log([&]() { spdlog::info("Pos-Create ComponentVector wiht ComponentType {} in location {:p}", typeID, (void*)vectCmp); });
        this->storage[typeID] = std::move(v);
        return vectCmp->components;
    }

    template <Moon::Concepts::Cmp_t CMP_t>
    std::vector<CMP_t> &ComponentStorage_t::getComponents()
    {
        auto typeID = CMP_t::getComponentType();
        auto it = this->storage.find(typeID);
        if (it != this->storage.end())
        {
            auto *comVect = dynamic_cast<Moon::Core::ComponentVect_t<CMP_t> *>(
                it->second.get());
            return comVect->components;
        }
        else
        {
            return this->createComponentVector<CMP_t>();
        }
    }

    template <Moon::Concepts::Cmp_t CMP_t>
    const std::vector<CMP_t> &ComponentStorage_t::getComponents() const
    {
        auto typeID = CMP_t::getComponentType();
        auto it = this->storage.find(typeID);
        if (it != this->storage.end())
        {
            auto *comVect = dynamic_cast<Moon::Core::ComponentVect_t<CMP_t> *>(
                it->second.get());
            return comVect->components;
        }
        else
        {
            throw "Asi no por favor !!!";
        }
    }

    Moon::Core::ComponentBase_t *
    ComponentStorage_t::deleteComponentByTypeIdAndEntityId(Moon::Alias::ComponentType cid, Moon::Alias::EntityId eid)
    {
        auto it = this->storage.find(cid);
        if (it == this->storage.end())
            return nullptr;
        Moon::Tools::Moon_Log([&]() { spdlog::info("Pre-Delete Component_t wiht ComponentType {} and eid {} in location {:p}", cid, eid, (void*)it->second.get()); });
        return it->second->deleteComponentByEntityId(eid);
    }

    ComponentStorage_t::~ComponentStorage_t() {Moon::Tools::Moon_Log([&]() { spdlog::info("Delete ComponentStorage_t in location {:p}", (void *)this); });}
} // namespace Moon::Core