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
#ifdef MOON_WINDOWS_CLANG
    for (ENT_t &var : this->entities)
    {
      if (var.eid == eid)
      {
        return &var;
      }
    }
#elif defined(MOON_WINDOWS_CYGWIN) || defined(MOON_PLATFORM_LINUX)
    auto itopt = this->findEntityIteratorById(eid);

    if (!itopt)
      return nullptr;

    auto it = *itopt;

    if (it + 1 != entities.end())
      *it = entities.back();
    entities.pop_back();
    return it.base();
#endif
    return nullptr;
  }
} // namespace Moon::Core
