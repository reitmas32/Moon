/**
 * @file ent_storage.hpp
 * @author Oswaldo Rafael Zamora Ramírez (rafa.zamo.rals@comunidad.unam.mx)
 * @version 0.0.1
 * @date 2021-03-03
 * @copyright Copyright (c) Moon 2020-2021 Oswaldo Rafael Zamora Ramírez
 *
 */
#pragma once

/**
 * @include vector
 */
#include <vector>

/**
 * @include unordered_map
 */
#include <unordered_map>

/**
 * @include memory
 */
#include <memory>

/**
 * @include alias.hpp
 */
#include <core/alias.hpp>

/**
 * @include concepts.hpp
 */
#include <core/concepts.hpp>

/**
 * @include cmp_vector.hpp
 */
#include <core/ent/ent_vect.hpp>

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
    /** It is a vector warehouse of Entities 
     * @subsubsection Stability
     * @image html assets/stability/stability_2.png
    */
    struct EntityStorage_t
    {
        /**
         * @brief Contructor Default
         */
        EntityStorage_t()
        {
            Moon::Tools::Logs::contructor("EntityStorage_t", this);
        }
        /**
         * @brief Destructor Default
         */
        ~EntityStorage_t()
        {
            Moon::Tools::Logs::destructor("EntityStorage_t", this);
        }

        /**
         * @brief Create a Entity object
         *
         * @tparam CMP_t Type of new Entity_t
         * @param eid Id of the Entity to which the Entity belongs
         * @param Ts... Params of Contructor of Entity_t
         * @pre The Entity_t to create must have a constructor with the specified parameters
         * @return CMP_t& This is a reference to new Entity_t
         */
        template <typename ENT_t, typename... Ts>
        ENT_t &createEntity(Moon::Alias::EntityId eid, Ts &&...args);

        /**
         * @brief Get the Entitys
         *
         * @tparam CMP_t Type of the Entity_t
         * @return std::vector<CMP_t>& Reference to vector of Entity_t's
         */
        template <typename ENT_t>
        std::vector<ENT_t> &getEntities();

        /**
         * @brief Get the Const Entitys
         *
         * @tparam CMP_t Type of the Entity_t
         * @return const std::vector<CMP_t>& Const Reference to vector of Entity_t's
         */
        template <typename ENT_t>
        const std::vector<ENT_t> &getEntities() const;

        /**
         * @brief Delete the a Entity_t
         *
         * @param cid Id of the Entity
         * @param eid Id of the Entity to which the Entity belongs
         * @return EntityBase_t* pointer of Entity_t Delete
         */
        EntityBase_t *
        deleteEntityByTypeIdAndEntityId(Moon::Alias::EntityType type, Moon::Alias::EntityId eid)
        {
            auto it = this->storage.find(type);
            if (it == this->storage.end())
                return nullptr;
            return it->second->deleteByEntityId(eid);
        }

        //TODO
        auto begin() { return this->storage.begin(); }

        //TODO
        auto end() { return this->storage.end(); }

    private:
        /**
         * @brief Create a Entity Vector object
         *
         * @tparam CMP_t Type of the Entity_t
         * @return std::vector<CMP_t>& 
         */
        template <typename ENT_t>
        std::vector<ENT_t> &createEntityVector();

        /**Map of the types and Vector<Entity_t's>*/
        std::unordered_map<Moon::Alias::EntityType,
                           std::unique_ptr<EntityBaseVect_t>>
            storage;
    };
} // namespace Moon::Core