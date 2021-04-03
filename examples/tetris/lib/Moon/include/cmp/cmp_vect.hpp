/**
 * @file component_vect.hpp
 * @author Oswaldo Rafael Zamora Ramírez (rafa.zamo.rals@comunidad.unam.mx)
 * @brief Wrapper de un Vector de Components
 * @version 0.1
 * @date 2021-03-03
 *
 * @copyright Copyright (c) Moon 2020-2021 Oswaldo Rafael Zamora Ramírez
 *
 */
#pragma once

// std::vector
#include <vector>

#include "../concepts.hpp"

/**
 * @brief Namespace del core del Motor
 *
 */
namespace Moon::Core {
    /**
     * @brief Wrapper de un Vector de Components
     *
     */
    struct ComponentBaseVect_t
    {
        /**
         * @brief Destructor de ComponentBaseVect_t object
         *
         */
        virtual ~ComponentBaseVect_t() = default;
    };

    /**
     * @brief Wrapper de un Vector de Components especificos
     *
     * @tparam CMP_t
     */
    template<Moon::Concepts::Cmp_t CMP_t>
    struct ComponentVect_t : ComponentBaseVect_t
    {
        // vector encapsulado
        std::vector<CMP_t> components;
    };
} // namespace Moon::Core
