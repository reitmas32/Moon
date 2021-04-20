/**
 * @file manager_base.hpp
 * @author Oswaldo Rafael Zamora Ramírez (rafa.zamo.rals@comunidad.unam.mx)
 * @brief 
 * @version 1.2.0
 * @date 2020-08-06
 * 
 * @copyright Copyright (c) Moon 2020-2021 Oswaldo Rafael Zamora Ramírez
 * 
 */
#pragma once

//Alias
#include <core/alias.hpp>

/**
 * @brief Namespace del core del Motor
 * 
 */
namespace Moon::Core
{
    /**
     * @brief Clase de la Que heredan todos los MAnages del Motor
     * 
     */
    struct ManagerBase_t
    {
        /**Identificador del siguiente tipo de GameContext*/
        inline static Moon::Alias::ManagerType nextType = 0;

        /**
         * @brief Contructor de ManagerBase_t object
         * 
         */
        ManagerBase_t(){
            Moon::Tools::Logs::contructor("ManagerBase_t", this);
        }

        /**
         * @brief Destructor de ManagerBase_t object
         * 
         */
        virtual ~ManagerBase_t(){
            Moon::Tools::Logs::destructor("ManagerBase_t", this);
        }
    };

} // namespace Moon::Core
