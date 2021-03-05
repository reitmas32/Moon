/**
 * @file cmp_base.hpp
 * @author Oswaldo Rafael Zamora Ramirez (rafa.zamo.rals@comunidad.unam.mx)
 * @version 0.0.1
 * @date 2020-08-03
 * @copyright Copyright (c) Moon 2020 Oswaldo Rafael Zamora Ramírez
 *
 */
#pragma once

/**
 * \include alias.hpp
 */
#include <core/alias.hpp>

/**
 * @brief Namespace of the Core the Moon
 * \namespace Moon::Core
 */
namespace Moon::Core {
    /**
     * @brief Class from which all Engine Components inherit
     * \image html assets/stability/stability_2.png
     */
    struct ComponentBase_t
    {
        /**Identifier of the following type of Component_t*/
        inline static Moon::Alias::ComponentType nextType = 0;
        
        /**Id of the Entity to which the Component belongs*/
        Moon::Alias::EntityId eid = 0;
        /** Contructor Default */
        ComponentBase_t() = default;

        /** Destroy the ComponentBase_t object is virtual*/
        virtual ~ComponentBase_t(){}
    };

} // namespace Moon::Core