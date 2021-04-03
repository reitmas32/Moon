/**
 * @file ent_vect.hpp
 * @author Oswaldo Rafael Zamora Ramírez (rafa.zamo.rals@comunidad.unam.mx)
 * @version 0.0.1
 * @date 2021-03-03
 * @copyright Copyright (c) Moon 2020-2021 Oswaldo Rafael Zamora Ramírez
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
 * \include moon_log.hpp
 */
#include <tools/moon_log.hpp>

/**
 * @brief Namespace of the Core the Moon
 * \namespace Moon::Core
 */
namespace Moon::Core
{
    /**
     * @brief Wrapper of std::vector of Entity_t's
     * \image html assets/stability/stability_2.png
     */
    struct EntityBaseVect_t
    {
        /**
         * @brief Destructor of ComponentBaseVect_t
         *
         */
        EntityBaseVect_t()
        {
            Moon::Tools::Logs::contructor("EntityBaseVect_t", this);
        }

        /**
         * @brief Contructor Default
         */
        virtual ~EntityBaseVect_t()
        {
            Moon::Tools::Logs::destructor("EntityBaseVect_t", this);
        }

        /**
         * @brief Delete the a Entity_t
         *
         * @param eid Id of the Entity to which the Component belongs
         * @return ComponentBase_t* pointer of Entity_t Delete
         */
        virtual EntityBase_t *deleteByEntityId(Moon::Alias::EntityId eid) = 0;
    };

    /**
     * @brief Wrapper of a Vector of specific Components
     * \image html assets/stability/stability_2.png
     * @tparam ENT_t Type of the Entity_t
     */
    template <typename ENT_t>
    struct EntityVect_t : EntityBaseVect_t
    {

        /**
         * @brief Constuctor of ComponentVect_t
         *
         */
        EntityVect_t()
        {
            Moon::Tools::Logs::contructor("EntityVect_t", this);
        }

        /**
         * @brief Destructor of ComponentVect_t
         *
         */
        ~EntityVect_t()
        {
            Moon::Tools::Logs::destructor("EntityVect_t", this);
        }

        /**
         * @brief Find Entity_t with Id equal eid
         * 
         * @param eid Id of the Entity to which the Component belongs
         * 
         * @return Entity_t* with Id equal eid
         */
        constexpr auto findEntityIteratorById(Moon::Alias::EntityId eid) noexcept;

        /**
         * @brief Delete the a Entity_t
         *
         * @param eid Id of the Entity to which the Component belongs
         * @return ComponentBase_t* pointer of Entity_t Delete
         */
        EntityBase_t *deleteByEntityId(Moon::Alias::EntityId eid) override;

        //private:
        /** Wrapped vector*/
        std::vector<ENT_t> entities;
    };
} // namespace Moon::Core
