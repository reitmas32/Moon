#pragma once

#include <core/man/manager.hpp>

namespace Moon::Core
{
    ManagerBase_t::ManagerBase_t()
    {
    }

    ManagerBase_t::~ManagerBase_t()
    {
    }

    template <typename Type>
    Manager_t<Type>::Manager_t()
    {
        Moon::Tools::Moon_Log([&]() { spdlog::info("Create Manager_t wiht ManagerType {}", this->getManagerType()); });
    }

    template <typename Type>
    Manager_t<Type>::~Manager_t()
    {
        Moon::Tools::Moon_Log([&]() { spdlog::info("Delete Manager_t wiht ManagerType {}", this->getManagerType()); });
    }

    template <class Type>
    Moon::Alias::ManagerType Manager_t<Type>::getManagerType()
    {
        static Moon::Alias::ManagerType type = ++nextType;
        return type;
    }
} // namespace Moon::Core
