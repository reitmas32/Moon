#pragma once

#include <core/cmp/cmp.hpp>

#include <tools/moon_log.hpp>

namespace Moon::Core
{
  template <class Type>
  Component_t<Type>::Component_t()
  {
    Moon::Tools::Moon_Log([&]() {
      spdlog::info("Create Default Component_t wiht ComponentType {} and eid {} in location {:p}",
                   this->getComponentType(), this->eid, (void *)this);
    });
  }

  template <class Type>
  Component_t<Type>::Component_t(Moon::Alias::EntityId eid)
  {
    this->eid = eid;
    Moon::Tools::Moon_Log([&]() {
      spdlog::info("Create Component_t wiht ComponentType {} and eid {} in location {:p}",
                   this->getComponentType(), this->eid, (void *)this);
    });
  }

  template <class Type>
  Component_t<Type>::~Component_t()
  { /*Nada*/
    //TODO:Hacer los logs en el core del motor
    Moon::Tools::Moon_Log([&]() {
      spdlog::info("Delete Component_t wiht ComponentType {} and eid {} in location {:p}",
                   this->getComponentType(), this->eid, (void *)this);
    });
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
    Moon::Tools::Moon_Log([&]() {
      spdlog::info("Create ComponentSingleton_t wiht ComponentType {} in location {:p}",
                   this->getComponentType(), (void *)this);
    });
  }

  template <class Type>
  ComponentSingleton_t<Type>::~ComponentSingleton_t()
  {
    Moon::Tools::Moon_Log([&]() {
      spdlog::info("Delete ComponentSingleton_t wiht ComponentType {} in location {:p}",
                   this->getComponentType(), (void *)this);
    });
  }

  template <class Type>
  Moon::Alias::ComponentType
  ComponentSingleton_t<Type>::getComponentType() noexcept
  {
    static Moon::Alias::ComponentType type = ++nextType;
    return type;
  }
} // namespace Moon::Core