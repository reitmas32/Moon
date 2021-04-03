#pragma once

#include <vector>

#include <core/concepts.hpp>

#include <optional>

#include <functional>

#include <tools/moon_log.hpp>

namespace Moon::Core
{
    struct EntityBaseVect_t
    {
        EntityBaseVect_t()
        {
            Moon::Tools::Logs::contructor("EntityBaseVect_t", this);
        }

        virtual ~EntityBaseVect_t()
        {
            Moon::Tools::Logs::destructor("EntityBaseVect_t", this);
        }

        virtual EntityBase_t *deleteByEntityId(Moon::Alias::EntityId eid) = 0;
    };

    template <typename ENT_t>
    struct EntityVect_t : EntityBaseVect_t
    {

        EntityVect_t()
        {
            Moon::Tools::Logs::contructor("EntityVect_t", this);
        }

        ~EntityVect_t()
        {
            Moon::Tools::Logs::destructor("EntityVect_t", this);
        }

        constexpr auto findEntityIteratorById(Moon::Alias::EntityId eid) noexcept;

        EntityBase_t *deleteByEntityId(Moon::Alias::EntityId eid) override;

        std::vector<ENT_t> entities;
    };
} // namespace Moon::Core
