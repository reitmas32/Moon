#pragma once

#include <core/cmp/cmp.hpp>

#include <tools/moon_log.hpp>

namespace Moon::Core
{
  template <class Type>
  Moon::Alias::ComponentType
  Component_t<Type>::getComponentType() noexcept
  {
    static Moon::Alias::ComponentType type = ++nextType;
    return type;
  }

  //---------------------------------------------------
  //---------------------------------------------------
  //---------------------------------------------------

  template <class Type>
  Moon::Alias::ComponentType
  ComponentSingleton_t<Type>::getComponentType() noexcept
  {
    static Moon::Alias::ComponentType type = ++nextType;
    return type;
  }
} // namespace Moon::Core