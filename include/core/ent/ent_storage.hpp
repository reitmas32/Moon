#pragma once

#include <vector>

#include <unordered_map>

#include <memory>

#include <core/alias.hpp>

#include <core/concepts.hpp>

#include <core/ent/ent_vect.hpp>

#include <tools/moon_log.hpp>

namespace Moon::Core
{
    struct EntityStorage_t
    {
        EntityStorage_t()
        {
        }

        ~EntityStorage_t()
        {
        }

        template <typename ENT_t, typename... Ts>
        ENT_t &createEntity(Moon::Alias::EntityId eid, Ts &&...args);

        template <typename ENT_t>
        std::vector<ENT_t> &getEntities();

        template <typename ENT_t>
        const std::vector<ENT_t> &getEntities() const;

        EntityBase_t *
        deleteEntityByTypeIdAndEntityId(Moon::Alias::EntityType type, Moon::Alias::EntityId eid);

    private:
        template <typename ENT_t>
        std::vector<ENT_t> &createEntityVector();

        /**Map of the types and Vector<Entity_t's>*/
        std::unordered_map<Moon::Alias::EntityType,
                           std::unique_ptr<EntityBaseVect_t>>
            storage;
    };
} // namespace Moon::Core