/**
 * @file cmp_storage.hpp
 * @author Oswaldo Rafael Zamora Ramírez (rafa.zamo.rals@comunidad.unam.mx)
 * @version 0.0.1
 * @date 2020-08-03
 * @copyright Copyright (c) Moon 2020 Oswaldo Rafael Zamora Ramírez
 *
 */
#pragma once

/**
 * \include vector
 */
#include <vector>

/**
 * \include unordered_map
 */
#include <unordered_map>

/**
 * \include memory
 */
#include <memory>

/**
 * \include alias.hpp
 */
#include <core/alias.hpp>

/**
 * \include concepts.hpp
 */
#include <core/concepts.hpp>

/**
 * \include cmp_vector.hpp
 */
#include <core/cmp/cmp_vect.hpp>

#include <tools/moon_log.hpp>

/**
 * @brief Namespace of the Core the Moon
 * \namespace Moon::Core
 */
namespace Moon::Core
{
    /** It is a vector warehouse of Components 
     * @subsubsection Stability
     * \image html assets/stability/stability_2.png
    */
    struct ComponentStorage_t
    {
        /**
         * @brief Contructor Default
         */
        ComponentStorage_t(){
            Moon::Tools::Logs::contructor("ComponentStorage_t", this);
        }

        virtual ~ComponentStorage_t(){
            Moon::Tools::Logs::destructor("ComponentStorage_t", this);
        }

        /**
         * @brief Create a Component object
         *
         * @tparam CMP_t Type of new Component_t
         * @param eid Id of the Entity to which the Component belongs
         * @param Ts... Params of Contructor of Component_t
         * @pre The Component_t to create must have a constructor with the specified parameters
         * @return CMP_t& This is a reference to new Component_t
         */
        template <Moon::Concepts::Cmp_t CMP_t, typename... Ts>
        CMP_t &createComponent(Moon::Alias::EntityId eid, Ts &&...args);

        /**
         * @brief Get the Components
         *
         * @tparam CMP_t Type of the Component_t
         * @return std::vector<CMP_t>& Reference to vector of Component_t's
         */
        template <Moon::Concepts::Cmp_t CMP_t>
        std::vector<CMP_t> &getComponents();

        /**
         * @brief Get the Const Components
         *
         * @tparam CMP_t Type of the Component_t
         * @return const std::vector<CMP_t>& Const Reference to vector of Component_t's
         */
        template <Moon::Concepts::Cmp_t CMP_t>
        const std::vector<CMP_t> &getComponents() const;


        /**
         * @brief Delete the a Component_t
         *
         * @param cid Id of the Component
         * @param eid Id of the Entity to which the Component belongs
         * @return ComponentBase_t* pointer of Component_t Delete
         */
        ComponentBase_t *
        deleteComponentByTypeIdAndEntityId(Moon::Alias::ComponentType cid, Moon::Alias::EntityId eid);

    private:
        /**
         * @brief Create a Component Vector object
         *
         * @tparam CMP_t Type of the Component_t
         * @return std::vector<CMP_t>& 
         */
        template <Moon::Concepts::Cmp_t CMP_t>
        std::vector<CMP_t> &createComponentVector();

        /**Map of the types and Vector<Component_t's>*/
        std::unordered_map<Moon::Alias::ComponentType,
                           std::unique_ptr<ComponentBaseVect_t>>
            storage;
    };
} // namespace Moon::Core