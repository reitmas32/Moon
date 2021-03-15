#pragma once

#include <core/cmp/cmp_vect.hpp>

namespace Moon::Core
{
    template <Moon::Concepts::Cmp_t CMP_t>
    constexpr auto ComponentVect_t<CMP_t>::findComponentIteratorById(Moon::Alias::EntityId eid) noexcept
    {
        std::optional itopt =
            std::find_if(components.begin(), components.end(),
                         [&eid](CMP_t &cmp) { return cmp.eid == eid; });
        if (*itopt == components.end())
            itopt.reset();

        return itopt;
    }

    template <Moon::Concepts::Cmp_t CMP_t>
    ComponentBase_t *ComponentVect_t<CMP_t>::deleteComponentByEntityId(Moon::Alias::EntityId eid)
    {
        auto itopt = this->findComponentIteratorById(eid);

        if (!itopt)
            return nullptr;

        auto it = *itopt;

        if (it + 1 != components.end())
            *it = components.back();
        components.pop_back();
        Moon::Tools::Moon_Log([&]() { spdlog::info("Pre-Delete Component_t"); });
        return it.base();
    }
} // namespace Moon::Core
