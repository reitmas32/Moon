/**
 * @file component.hpp
 * @author Oswaldo Rafael Zamora Ramírez (rafa.zamo.rals@comunidad.unam.mx)
 * @brief Clase de la que heredan todos los components del Motor
 * @version 0.1
 * @date 2021-03-03
 *
 * @copyright Copyright (c) Moon 2020-2021 Oswaldo Rafael Zamora Ramírez
 *
 */
#pragma once

// Alias
#include "../../include/alias.hpp"

// Component Base
#include "../../include/cmp/cmp_base.hpp"

/**
 * @brief Namespace del core del Motor
 *
 */
namespace Moon::Core {

    /**
     * @brief Clase de la que heredan todos los Components del Motor
     *
     * @tparam Type
     */
    template<class Type>
    struct Component_t : public ComponentBase_t
    {
        /**ID de la Entity a la que pertenece el Component*/
        Moon::Alias::EntityId eid = 0;

        /**
         * @brief Construct a new Component_t object
         *
         */
        Component_t();

        /**
         * @brief Construct a new Component_t object
         *
         * @param eid Id de la ENtity a la que pertenece el Component
         */
        Component_t(Moon::Alias::EntityId eid);

        /**
         * @brief Destroy the Component_t object
         *
         */
        virtual ~Component_t() = 0;

        /**
         * @brief Get the Component Type object
         *
         * @return Moon::Alias::ComponentType
         */
        static Moon::Alias::ComponentType getComponentType() noexcept;
    };

} // namespace Moon::Core