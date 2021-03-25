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
        virtual ~EntityBaseVect_t() = default;

        EntityBaseVect_t() = default;

        virtual EntityBase_t *deleteByEntityId(Moon::Alias::EntityId eid) = 0;
    };

    template <typename ENT_t>
    struct EntityVect_t : EntityBaseVect_t
    {

        constexpr auto findEntityIteratorById(Moon::Alias::EntityId eid) noexcept;

        EntityBase_t *deleteByEntityId(Moon::Alias::EntityId eid) override final;

        std::vector<ENT_t> entities;
    };
} // namespace Moon::Core
