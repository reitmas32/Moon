#pragma once

#include <iostream>
#include <unordered_map>
#include <concepts>

/**
 * @brief Namespace de los alias del motor
 * 
 */
namespace Moon::Alias
{
    /**
     * @brief Tipo definido para dar un ID a cada entidad
     * 
     */
    using EntityId = std::size_t;

    /**
     * @brief Tipos definidos para identificar cada tipo distinto de Objeto en el Motor
     * 
     */
    using EntityType = std::uint16_t;
    using SystemType = std::uint16_t;
    using ComponentType = std::uint16_t;
    using GameContextType = std::uint16_t;
    using GameContextVoidType = std::uint16_t;
    using StateType = std::uint16_t;
    using EventType = std::uint16_t;
    using ManagerType = std::uint16_t;
    using AplicationType = std::uint16_t;
    using WindowType = std::uint16_t;

    /**
     * @brief Tipo para identificar los eventos en el Motor
     * 
     */
    using EventCode = std::uint16_t;

} // namespace Moon::Alias
