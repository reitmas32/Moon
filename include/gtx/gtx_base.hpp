/**
 * @file game_context_base.hpp
 * @author Oswaldo Rafael Zamora Ramírez (rafa.zamo.rals@comunidad.unam.mx)
 * @brief Clase GameContext !!! Es laencargada de alamacenar Los datos de una
 * App
 * @version 0.1
 * @date 2020-08-03
 *
 * @copyright Copyright (c) Moon 2020 Oswaldo Rafael Zamora Ramírez
 *
 */
#pragma once

// Alias
#include <alias.hpp>

/**
 * @brief Namespace del core del Motor
 *
 */
namespace Moon::Core {
    /**
     * @brief Clase GameContext !!! Es laencargada de alamacenar Los datos de
     * una App
     *
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
        GameContextBase_t() = default;

        /**
         * @brief Destructor de GameContextBase_t object
         *
         */
        virtual ~GameContextBase_t(){}
    };

} // namespace Moon::Core