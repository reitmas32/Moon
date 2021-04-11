/**
 * @file cmp.hpp
 * @author Oswaldo Rafael Zamora Ramírez (rafa.zamo.rals@comunidad.unam.mx)
 * @version 0.0.1
 * @date 2021-03-03
 * @copyright Copyright (c) Moon 2020-2021 Oswaldo Rafael Zamora Ramírez
 *
 */
#pragma once

/**
 * @include alias.hpp
 */
#include <core/alias.hpp>

/**
 * @include cmp/cmp_base.hpp
 */
#include <core/cmp/cmp_base.hpp>

/**
 * @brief Namespace of the Core the Moon
 * @namespace Moon::Core
 */
namespace Moon::Core
{
    /**
     * @subsubsection Example
     * @code{.cpp}
     * struct Sprite_t : Moon::Core::Component_t<Sprite_t>{
     * private:
     *      std::vector<Image> sprite;
     * public:
     *      Sprite_t(){}
     * 
     *      Sprite_t(Moon::Alias::EntityId eid) : Component_t<Sprite_t>(eid){
     *          //TODO:All Constructor
     *      }
     * 
     *      ~Sprite(){
     *          //TODO:All Destructor
     *      }
     * };
     * @endcode
     */
    /**
     * @brief Class from which all Engine Components inherit
     * @subsubsection Stability
     * @image html assets/stability/stability_2.png
     * @tparam Type Is a new Component Following the CRTP
     */
    template <class Type>
    struct Component_t : public ComponentBase_t
    {
        /**Overloaded constructor Default*/
        Component_t(){
            Moon::Tools::Logs::contructor("Component_t", this);
        }

        /**
         * Overloaded constructor with Moon::Alias::EntityId
         *
         * @param eid Id of the Entity to which the Component belongs
         */
        Component_t(Moon::Alias::EntityId eid)
        {
            this->eid = eid;
            Moon::Tools::Logs::contructor("Component_t", this, " and eid :", this->eid);
        }

        /** Destroy the Component_t object is virtual*/
        virtual ~Component_t(){
            Moon::Tools::Logs::destructor("Component_t", this, " and eid :", this->eid);
        }

        /**
         * @brief Get the Component Type object
         * 
         * @pre None
         * 
         * @post The return is unique for each Component_t
         * 
         * @return Moon::Alias::ComponentType
         */
        static Moon::Alias::ComponentType getComponentType() noexcept;
    };
    template <class Type>
    struct ComponentSingleton_t : protected ComponentBase_t
    {
        ComponentSingleton_t(){
            Moon::Tools::Logs::contructor("ComponentSingleton_t", this);
        }

        virtual ~ComponentSingleton_t(){
            Moon::Tools::Logs::destructor("ComponentSingleton_t", this);
        }

        static Moon::Alias::ComponentType getComponentType() noexcept;
    };

} // namespace Moon::Core
