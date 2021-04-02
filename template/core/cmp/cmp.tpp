#pragma once

#include <core/cmp/cmp.hpp>

#include <tools/moon_log.hpp>

namespace Moon::Core
{
  template <class Type>
  Component_t<Type>::Component_t()
  {
  }

  template <class Type>
  Component_t<Type>::Component_t(Moon::Alias::EntityId eid)
  {
    this->eid = eid;
  }

  template <class Type>
  Component_t<Type>::~Component_t()
  { /*Nada*/
    //TODO:Hacer los logs en el core del motor

  }

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
  ComponentSingleton_t<Type>::ComponentSingleton_t()
  {
  }

  template <class Type>
  ComponentSingleton_t<Type>::~ComponentSingleton_t()
  {
  }

  template <class Type>
  Moon::Alias::ComponentType
  ComponentSingleton_t<Type>::getComponentType() noexcept
  {
    static Moon::Alias::ComponentType type = ++nextType;
    return type;
  }
} // namespace Moon::Core