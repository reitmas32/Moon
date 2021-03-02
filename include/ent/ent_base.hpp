/**
 * @file entity_base.hpp
 * @author Oswaldo Rafael Zamora Ramirez (rafa.zamo.rals@comunidad.unam.mx)
 * @brief Clase de la que hereda cualquier entity del Motor
 * @version 0.1
 * @date 2020-08-03
 *
 * @copyright Copyright (c) Moon 2020 Oswaldo Rafael Zamora Ramírez
 *
 */
#pragma once

// Alias de tipos
#include <alias.hpp>

#include <cmp/cmp_base.hpp>

// Component_Base
#include <cmp/cmp_base.hpp>

/**
 * @brief Namespace del core del Motor
 *
 */
namespace Moon::Core {
    // Redefinicion de un vector de Tipos y Components
    using MapCmps_t =
      std::unordered_map<Moon::Alias::ComponentType, ComponentBase_t*>;

    /**
     * @brief Clase de la que hereda cualquier entity del Motor
     *
     */
    struct EntityBase_t
    {

        /**Identificador del siguiente tipo de Entity*/
        inline static Moon::Alias::EntityType nextType = 0;

        /**Mapa de Tipos y Components*/
        MapCmps_t components;

      public:
        /**
         * @brief Construct a new EntityBase_t object
         *
         */
        EntityBase_t() = default;

        /**
         * @brief Destroy the EntityBase_t object
         *
         */
        virtual ~EntityBase_t() {}

        /**
         * @brief Añade un Component a this
         *
         * @tparam CMP_t
         * @param cmp
         */
        template<class CMP_t>
        requires std::is_base_of<Moon::Core::ComponentBase_t, CMP_t>::value void
        addComponent(CMP_t* cmp);

        /**
         * @brief Get the Component object
         *
         * @tparam CMP_t
         * @return CMP_t*
         */
        template<class CMP_t>
        requires std::is_base_of<Moon::Core::ComponentBase_t, CMP_t>::value
          CMP_t*
          getComponent();
    };

} // namespace Moon::Core