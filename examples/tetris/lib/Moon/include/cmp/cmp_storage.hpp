/**
 * @file component_storage.hpp
 * @author Oswaldo Rafael Zamora Ramírez (rafa.zamo.rals@comunidad.unam.mx)
 * @brief Es un almacen de Vectores de Components
 * @version 0.1
 * @date 2021-03-03
 *
 * @copyright Copyright (c) Moon 2020-2021 Oswaldo Rafael Zamora Ramírez
 *
 */
#pragma once

// std::vector
#include <vector>

// std::unordered_map
#include <unordered_map>

// std::unique_ptr
#include <memory>

// Alias
#include "../alias.hpp"

#include "../concepts.hpp"

// Wrapper de un vector<Components>
#include "cmp_vect.hpp"

/**
 * @brief Namespace del core del Motor
 *
 */
namespace Moon::Core {
    /**
     * @brief Es un almacen de Vectores de Components
     *
     */
    struct ComponentStorage_t
    {
        /**
         * @brief Contructor de ComponentStorage_t object
         *
         */
        ComponentStorage_t();

        /**
         * @brief Create a Component object
         *
         * @tparam CMP_t
         * @param eid
         * @return CMP_t&
         */
        template<Moon::Concepts::Cmp_t CMP_t, typename... Ts>
        CMP_t& createComponent(Moon::Alias::EntityId eid, Ts&&... args);

        /**
         * @brief Get the Components object
         *
         * @tparam CMP_t
         * @return std::vector<CMP_t>&
         */
        template<Moon::Concepts::Cmp_t CMP_t>
        std::vector<CMP_t>& getComponents();

        /**
         * @brief Get the Components object
         *
         * @tparam CMP_t
         * @return const std::vector<CMP_t>&
         */
        template<Moon::Concepts::Cmp_t CMP_t>
        const std::vector<CMP_t>& getComponents() const;

        /**Mapa de tipos y Vector<Components>*/
        std::unordered_map<Moon::Alias::ComponentType,
                           std::unique_ptr<ComponentBaseVect_t>>
          storage;
        /**
         * @brief Create a Component Vector object
         *
         * @tparam CMP_t
         * @return std::vector<CMP_t>&
         */
        template<Moon::Concepts::Cmp_t CMP_t>
        std::vector<CMP_t>& createComponentVector();
    };
} // namespace Moon::Core