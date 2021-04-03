/**
 * @file cmp_base.hpp
 * @author Oswaldo Rafael Zamora Ramirez (rafa.zamo.rals@comunidad.unam.mx)
 * @version 1.2.0
 * @date 2021-03-03
 * @copyright Copyright (c) Moon 2020-2021-2021 Oswaldo Rafael Zamora Ramírez
 *
 */
#pragma once

/**
 * \include alias.hpp
 */
#include <core/alias.hpp>

/**
 * \include moon_log.hpp
 */
#include <tools/moon_log.hpp>

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
        ComponentBase_t(){
            Moon::Tools::Logs::contructor("ComponentBase_t", this);
        }

        /** Destroy the ComponentBase_t object is virtual*/
        virtual ~ComponentBase_t(){
            Moon::Tools::Logs::destructor("ComponentBase_t", this);
        }
    };

} // namespace Moon::Core