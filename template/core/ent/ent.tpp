#pragma once

#include <core/ent/ent.hpp>

namespace Moon::Core
{
  template <class Type>
  Moon::Alias::EntityType Entity_t<Type>::getEntityType() noexcept
  {
    static Moon::Alias::EntityType type = ++nextType;
    return type;
  }

  template <class Type>
  void Entity_t<Type>::updateComponent(Moon::Alias::ComponentType cid, ComponentBase_t *cmp_ptr)
  {
    //assert(cmp_ptr != nullptr, "Error Null Component_t in the func [[updateComponent]]");
    auto it = this->components.find(cid);
    if (it != this->components.end())
    {
      it->second = cmp_ptr;
    }
  }
} // namespace Moon::Core