#pragma once

#include <core/ent/ent.hpp>

namespace Moon::Core
{

  template <class Type>
  Entity_t<Type>::Entity_t(Moon::Alias::EntityId eid)
      : eid{eid}
  {
    Moon::Tools::Moon_Log([&]() {
      spdlog::info("Create Default Entity_t wiht EntityType {} in location {:p}",
                   this->eid, (void *)this);
    });
  }

  template <class Type>
  Entity_t<Type>::~Entity_t()
  {
    Moon::Tools::Moon_Log([&]() {
      spdlog::info("Delete Default Entity_t wiht EntityType {} and {:p}",
                   this->eid, (void *)this);
    });
  }

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
    Moon::Tools::Moon_Log([&]() { spdlog::info("updateComponent wiht ComponentType {} and eid {}", cid, this->eid); });
  }
} // namespace Moon::Core