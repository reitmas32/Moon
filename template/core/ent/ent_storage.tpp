#pragma once

#include <core/ent/ent_storage.hpp>

#include <core/ent/ent_vect.tpp>

#define NUM_CMPS 100

namespace Moon::Core
{

    template <typename ENT_t, typename... Ts>
    ENT_t &EntityStorage_t::createEntity(Moon::Alias::EntityId eid,
                                         Ts &&...args)
    {
        auto &v = this->getEntities<ENT_t>();
        auto &ent = v.emplace_back(eid, args...);
        return ent;
    }

    template <typename ENT_t>
    std::vector<ENT_t> &EntityStorage_t::createEntityVector()
    {
        auto v = std::make_unique<Moon::Core::EntityVect_t<ENT_t>>();
        v->entities.reserve(NUM_CMPS);
        auto typeID = ENT_t::getEntityType();
        auto *vectCmp = v.get();
        this->storage[typeID] = std::move(v);
        return vectCmp->entities;
    }

    template <typename ENT_t>
    std::vector<ENT_t> &EntityStorage_t::getEntities()
    {
        auto typeID = ENT_t::getEntityType();
        auto it = this->storage.find(typeID);
        if (it != this->storage.end())
        {
            auto *entVect = dynamic_cast<Moon::Core::EntityVect_t<ENT_t> *>(
                it->second.get());
            return entVect->entities;
        }
        else
        {
            return this->createEntityVector<ENT_t>();
        }
    }

    template <typename ENT_t>
    const std::vector<ENT_t> &EntityStorage_t::getEntities() const
    {
        auto typeID = ENT_t::getEntityType();
        auto it = this->storage.find(typeID);
        if (it != this->storage.end())
        {
            auto *entVect = dynamic_cast<Moon::Core::EntityVect_t<ENT_t> *>(
                it->second.get());
            return entVect->entities;
        }
        else
        {
            throw "Asi no por favor !!!";
        }
    }
    /*
    Moon::Core::EntityBase_t *
    EntityStorage_t::deleteEntityByTypeIdAndEntityId(Moon::Alias::EntityType type, Moon::Alias::EntityId eid)
    {
        auto it = this->storage.find(type);
        if (it == this->storage.end())
            return nullptr;
        return it->second->deleteByEntityId(eid);
    }
    */
} // namespace Moon::Core