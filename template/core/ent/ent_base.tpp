#pragma once

#include <core/ent/ent_base.hpp>

namespace Moon::Core
{
  template <MOON_IS_CMP_T CMP_t>
  void
  EntityBase_t::addComponent(CMP_t *cmp)
  {
    this->components.insert({CMP_t::getComponentType(), cmp});
  }

  template <MOON_IS_CMP_T CMP_t>
  CMP_t *
  EntityBase_t::getComponent()
  {
    auto i = components.find(CMP_t::getComponentType());

    if (i != components.end())
    {
      return static_cast<CMP_t *>(i->second);
    }

    return nullptr;
  }
} // namespace Moon::Core