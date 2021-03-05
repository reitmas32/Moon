/**
 * @file entity.hpp
 * @author Oswaldo Rafael Zamora Ramirez (rafa.zamo.rals@comunidad.unam.mx)
 * @version 0.0.1
 * @date 2020-08-03
 *
 * @copyright Copyright (c) Moon 2020 Oswaldo Rafael Zamora Ramírez
 *
 */
#pragma once

/**
 * \include alias.hpp
 */
#include <core/alias.hpp>

/**
 * \include core/concepts.hpp
 */
#include <core/concepts.hpp>

/**
 * \include core/ent/ent_base.hpp
 */
#include <core/ent/ent_base.hpp>

/**
 * @brief Namespace of the Core the Moon
 * \namespace Moon::Core
 */
namespace Moon::Core {
    /**
     * @subsubsection Example
     * @code{.cpp}
     * struct Pacman : Moon::Core::Entity_t<Pacman>{
     * public:
     *      Pacman(){}
     * 
     *      Pacman(Moon::Alias::EntityId eid) : Entity_t<Pacman>(eid){
     *          //TODO:All Constructor
     *      }
     * 
     *      ~Pacman(){
     *          //TODO:All Destructor
     *      }
     * };
     * @endcode
     */
    /**
     * @brief Class from which all Engine Entity inherit
     * @subsubsection Stability
     * \image html assets/stability/stability_2.png
     * @tparam Type Is a new Component Following the CRTP
     */
    template<class Type>
    struct Entity_t : public EntityBase_t
    {
        /**ID of the Entity*/
        Moon::Alias::EntityId eid = 0;

        /**Overloaded constructor Default*/
        Entity_t();

        /**
         * Overloaded constructor with Moon::Alias::EntityId
         *
         * @param eid Id of the Entity
         */
        Entity_t(Moon::Alias::EntityId eid);

        /** Destroy the Entity_t object is virtual*/
        virtual ~Entity_t() = 0;

        /**
         * @brief Get the Entity Type object
         * 
         * @pre None
         * 
         * @post The return is unique for each Entity_t
         * 
         * @return Moon::Alias::EntityType
         */
        static Moon::Alias::EntityType getEntityType() noexcept;

        /**
         * @brief Update the Component_t
         * 
         * @pre cmp_ptr not nullptr
         * 
         * @post The return is unique for each Entity_t
         * 
         * @return Moon::Alias::EntityType
         */
        void updateComponent(Moon::Alias::ComponentType cid, ComponentBase_t* cmp_ptr);

        /**
         * @brief override begin() the Component_t
         * 
         * @post The return is Map for Component_t
         * 
         * @return MapCmps_t
         */
        auto begin() {return this->components.begin();}

        /**
         * @brief override end() the Component_t
         * 
         * @post The return is Map for Component_t
         * 
         * @return MapCmps_t
         */
        auto end() {return this->components.end();}
    };

} // namespace Moon::Core