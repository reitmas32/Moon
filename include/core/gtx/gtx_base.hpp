/**
 * @file game_context_base.hpp
 * @author Oswaldo Rafael Zamora Ramírez (rafa.zamo.rals@comunidad.unam.mx)
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
 * @brief Namespace del core del Motor
 *
 */
namespace Moon::Core {
    /**
     * @brief Clase GameContext !!! Es la en cargada de alamacenar Los datos de
     * una App
     * @image html assets/stability/stability_2.png
     */
    struct GameContextBase_t
    {
        /**Identificador del siguiente tipo de GameContext*/
        inline static Moon::Alias::GameContextType nextType{ 0 };

        /**Identificador del siguiente ID de Entity*/
        inline static Moon::Alias::EntityId nextId{ 0 };

        /**
         * @brief Contructor de GameContextBase_t object
         *
         */
        //TODO:LOGS
        GameContextBase_t(){
            Moon::Tools::Logs::contructor("GameContextBase_t", this);
        }

        /**
         * @brief Destructor de GameContextBase_t object
         *
         */
        //TODO:LOGS
        virtual ~GameContextBase_t(){
            Moon::Tools::Logs::destructor("GameContextBase_t", this);
        }
    };

} // namespace Moon::Core