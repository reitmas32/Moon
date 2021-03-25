#pragma once

#include <core/ent/ent_vect.hpp>

namespace Moon::Core
{
    template <typename ENT_t>
    constexpr auto EntityVect_t<ENT_t>::findEntityIteratorById(Moon::Alias::EntityId eid) noexcept
    {
        std::optional itopt =
            std::find_if(entities.begin(), entities.end(),
                         [&eid](ENT_t &cmp) { return cmp.eid == eid; });
        if (*itopt == entities.end())
            itopt.reset();

        return itopt;
    }

    template <typename ENT_t>
    EntityBase_t *EntityVect_t<ENT_t>::deleteByEntityId(Moon::Alias::EntityId eid)
    {
        auto itopt = this->findEntityIteratorById(eid);

        if (!itopt)
            return nullptr;

        auto it = *itopt;

        if (it + 1 != entities.end())
            *it = entities.back();
        entities.pop_back();
        Moon::Tools::Moon_Log([&]() { spdlog::info("Pre-Delete in EntityVect_t<ENT_t> Entity_t {} and {}", it.base()->eid, (void*)it.base()); });
        return it.base();
    }
} // namespace Moon::Core
