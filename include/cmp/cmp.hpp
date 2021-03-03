/**
 * @file component.hpp
 * @author Oswaldo Rafael Zamora Ramírez (rafa.zamo.rals@comunidad.unam.mx)
 * @brief Clase de la que heredan todos los components del Motor
 * @version 0.1
 * @date 2020-08-03
 *  
 * @copyright Copyright (c) Moon 2020 Oswaldo Rafael Zamora Ramírez
 *
 */
#pragma once

/**
 * \headerfile alias.hpp
 */
#include <alias.hpp>

/**
 * \headerfile cmp/cmp_base.hpp
 */
#include <cmp/cmp_base.hpp>

/**
 * @brief Namespace del core del Motor
 * \namespace Moon::Core
 */
namespace Moon::Core {

    /**
     * @brief Clase de la que heredan todos los Components del Motor
     * \image html assets/stability/stability_2.png
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