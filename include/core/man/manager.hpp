/**
 * @file manager.hpp
 * @author Oswaldo Rafael Zamora Ramírez (rafa.zamo.rals@comunidad.unam.mx)
 * @brief 
 * @version 0.1
 * @date 2020-08-06
 * 
 * @copyright Copyright (c) Moon 2020 Oswaldo Rafael Zamora Ramírez
 * 
 */
#pragma once

//ManagerBase
#include <core/man/manager_base.hpp>

#include <tools/moon_log.hpp>

/**
 * @brief Namespace del core del Motor
 * 
 */
namespace Moon::Core
{
    /**
     * @brief Clase de la Que heredan todos los MAnages del Motor
     * 
     * @tparam Type 
     */
    template<typename Type>
    struct Manager_t : public ManagerBase_t
    {
        /**
         * @brief Contructor de Manager_t object
         * 
         */
        //TODO:LOGS
        Manager_t() = default;

        /**
         * @brief Destructor de Manager_t object
         * 
         */
        //TODO:LOGS
        virtual ~Manager_t() = default;

        /**
         * @brief Get the Manager Type object
         * 
         * @return Moon::Alias::ManagerType 
         */
        static Moon::Alias::ManagerType getManagerType();
    };
    
} // namespace Moon::Core
