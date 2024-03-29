/**
 * @file system_base.hpp
 * @author Oswaldo Rafael Zamora Ramirez (rafa.zamo.rals@comunidad.unam.mx)
 * @brief Clase de la que heredan todos los systemas del Motor
 * @version 0.1
 * @date 2021-03-03
 *
 * @copyright Copyright (c) Moon 2020-2021 Oswaldo Rafael Zamora Ramírez
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
     * @brief Clase de la que heredan todos los systemas del Motor
     *
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
        SystemBase_t();

        /**
         * @brief Destructor de SystemBase_t object
         *
         */
        virtual ~SystemBase_t() = 0;

        /**
         * @brief Metodo que indica si el sistema sigue alive
         *
         * @return true
         * @return false
         */
        virtual bool alive() = 0;
    };

} // namespace Moon::Core