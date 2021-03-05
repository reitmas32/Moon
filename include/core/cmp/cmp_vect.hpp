/**
 * @file cmp_vect.hpp
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
 * \include concepts.hpp
 */
#include <core/concepts.hpp>

/**
 * \include optional
 */
#include <optional>

/**
 * \include functional
 */
#include <functional>

/**
 * @brief Namespace of the Core the Moon
 * \namespace Moon::Core
 */
namespace Moon::Core
{
    /**
     * @brief Wrapper of std::vector of Component_t's
     * \image html assets/stability/stability_2.png
     */
    struct ComponentBaseVect_t
    {
        /**
         * @brief Destructor of ComponentBaseVect_t
         *
         */
        virtual ~ComponentBaseVect_t() = default;

        /**
         * @brief Contructor Default
         */
        ComponentBaseVect_t() = default;

        /**
         * @brief Delete the a Component_t
         *
         * @param eid Id of the Entity to which the Component belongs
         * @return ComponentBase_t* pointer of Component_t Delete
         */
        virtual ComponentBase_t *deleteComponentByEntityId(Moon::Alias::EntityId eid) = 0;
    };

    /**
     * @brief Wrapper of a Vector of specific Components
     * \image html assets/stability/stability_2.png
     * @tparam CMP_t Type of the Component_t
     */
    template <Moon::Concepts::Cmp_t CMP_t>
    struct ComponentVect_t : ComponentBaseVect_t
    {

        /**
         * @brief Find Component_t with Id equal eid
         * 
         * @param eid Id of the Entity to which the Component belongs
         * 
         * @return Component_t* with Id equal eid
         */
        constexpr auto findComponentIteratorById(Moon::Alias::EntityId eid) noexcept;

        /**
         * @brief Delete the a Component_t
         *
         * @param eid Id of the Entity to which the Component belongs
         * @return ComponentBase_t* pointer of Component_t Delete
         */
        ComponentBase_t *deleteComponentByEntityId(Moon::Alias::EntityId eid) override final;

    //private:
        /** Wrapped vector*/
        std::vector<CMP_t> components;
    };
} // namespace Moon::Core
