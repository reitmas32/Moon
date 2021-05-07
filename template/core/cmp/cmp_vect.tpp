#pragma once

#include <core/cmp/cmp_vect.hpp>

namespace Moon::Core
{
  template <MOON_IS_CMP_T CMP_t>
  constexpr auto
  ComponentVect_t<CMP_t>::findComponentIteratorById(Moon::Alias::EntityId eid) noexcept
  {
    std::optional itopt =
        std::find_if(components.begin(), components.end(),
                     [&eid](CMP_t &cmp) { return cmp.eid == eid; });
    if (*itopt == components.end())
      itopt.reset();

    return itopt;
  }

  template <MOON_IS_CMP_T CMP_t>
  ComponentBase_t *
  ComponentVect_t<CMP_t>::deleteComponentByEntityId(Moon::Alias::EntityId eid)
  {
#ifdef MOON_WINDOWS_CLANG
    for (CMP_t &var : this->components)
    {
      if (var.eid == eid)
      {
        return &var;
      }
    }
#elif defined(MOON_WINDOWS_CYGWIN) || defined(MOON_PLATFORM_LINUX)
    auto itopt = this->findComponentIteratorById(eid);

    if (!itopt)
      return nullptr;

    auto it = *itopt;

    if (it + 1 != components.end())
      *it = components.back();
    components.pop_back();
    return it.base();
#else 
    return nullptr;
#endif
    return nullptr;
  }
} // namespace Moon::Core
