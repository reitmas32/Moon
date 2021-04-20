/**
 * @file system_base.hpp
 * @author Oswaldo Rafael Zamora Ramirez (rafa.zamo.rals@comunidad.unam.mx)
 * @brief Clase de la que heredan todos los systemas del Motor
 * @version 1.2.0
 * @date 2021-03-03
 *
 * @copyright Copyright (c) Moon 2020-2021 Oswaldo Rafael Zamora Ramírez
 *
 */
#pragma once

// Alias
#include <core/alias.hpp>

/**
 * @include moon_log.hpp
 */
#include <tools/moon_log.hpp>

/**
 * @brief Namespace del core del Motor
 *
 */
namespace Moon::Core {
    /**
     * @brief Clase de la que heredan todos los systemas del Motor
     * @image html assets/stability/stability_2.png
     */
    struct SystemBase_t
    {
        /**ID de la Entity a la que pertenece el Component*/
        inline static Moon::Alias::SystemType nextType = 0;

      public:
        /**
         * @brief Contructor de SystemBase_t object
         *
         */
        SystemBase_t(){
          Moon::Tools::Logs::contructor("SystemBase_t", this);
        }

        /**
         * @brief Destructor de SystemBase_t object
         *
         */
        virtual ~SystemBase_t(){
          Moon::Tools::Logs::destructor("SystemBase_t", this);
        }

        /**
         * @brief Metodo que indica si el sistema sigue alive
         *
         * @return true
         * @return false
         */
        virtual bool alive() = 0;
    };

} // namespace Moon::Core