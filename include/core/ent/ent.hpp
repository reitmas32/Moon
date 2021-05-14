/**
 * @file ent.hpp
 * @author Oswaldo Rafael Zamora Ramirez (rafa.zamo.rals@comunidad.unam.mx)
 * @version 0.0.1
 * @date 2021-03-03
 *
 * @copyright Copyright (c) Moon 2020-2021 Oswaldo Rafael Zamora Ramírez
 *
 */
#pragma once

/**
 * @include alias.hpp
 */
#include <core/alias.hpp>

/**
 * @include core/concepts.hpp
 */
#include <core/concepts.hpp>

/**
 * @include core/ent/ent_base.hpp
 */
#include <core/ent/ent_base.hpp>

/**
 * @include moon_log.hpp
 */
#include <tools/moon_log.hpp>

/**
 * @brief Namespace of the Core the Moon
 * @namespace Moon::Core
 */
namespace Moon::Core
{
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
     * @image html assets/stability/stability_2.png
     * @tparam Type Is a new Component Following the CRTP
     */
    template <class Type>
    struct Entity_t : public EntityBase_t
    {
        /**ID of the Entity*/
        Moon::Alias::EntityId eid = 0;

        /**Overloaded constructor Default*/
        //TODO:LOGS
        Entity_t(){
            Moon::Tools::Logs::contructor("Entity_t", this);
        }

        /**
         * Overloaded constructor with Moon::Alias::EntityId
         *
         * @param eid Id of the Entity
         */
        //TODO:LOGS
        Entity_t(Moon::Alias::EntityId eid) : eid{eid}
        {
            Moon::Tools::Logs::contructor("Entity_t", this, " and eid : ", this->eid);
        }

        /** Destroy the Entity_t object is virtual*/
        //TODO:LOGS
        virtual ~Entity_t(){
            Moon::Tools::Logs::destructor("Entity_t", this, " and eid : ", this->eid);
        }

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
        void updateComponent(Moon::Alias::ComponentType cid, ComponentBase_t *cmp_ptr);

        /**
         * @brief override begin() the Component_t
         * 
         * @post The return is Map for Component_t
         * 
         * @return MapCmps_t
         */
        auto begin() { return this->components.begin(); }

        /**
         * @brief override end() the Component_t
         * 
         * @post The return is Map for Component_t
         * 
         * @return MapCmps_t
         */
        auto end() { return this->components.end(); }
    };

} // namespace Moon::Core