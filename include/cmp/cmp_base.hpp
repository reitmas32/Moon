/**
 * @file component_base.hpp
 * @author Oswaldo Rafael Zamora Ramirez (rafa.zamo.rals@comunidad.unam.mx)
 * @brief Clase de la que heredan todos los components del Motor
 * @version 0.1
 * @date 2020-08-03
 *
 * @copyright Copyright (c) Moon 2020 Oswaldo Rafael Zamora Ramírez
 *
 */
#pragma once

// Alias
#include "../alias.hpp"

/**
 * @brief Namespace del core del Motor
 *
 */
namespace Moon::Core {
    /**
     * @brief Clase de la que heredan todos los components del Motor
     *
     */
    struct ComponentBase_t
    {
        /**Identificador del siguiente tipo de Componet*/
        inline static Moon::Alias::ComponentType nextType = 0;

        /**
         * @brief Construct a new ComponentBase_t object
         *
         */
        ComponentBase_t() = default;

        /**
         * @brief Destroy the ComponentBase_t object
         *
         */
        virtual ~ComponentBase_t(){}
    };

} // namespace Moon::Core