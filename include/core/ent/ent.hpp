/**
 * @file entity.hpp
 * @author Oswaldo Rafael Zamora Ramirez (rafa.zamo.rals@comunidad.unam.mx)
 * @brief Clase de la que hereda cualquier entity del Motor
 * @version 0.1
 * @date 2020-08-03
 *
 * @copyright Copyright (c) Moon 2020 Oswaldo Rafael Zamora Ramírez
 *
 */
#pragma once

#include <core/alias.hpp>
#include <core/concepts.hpp>
#include <core/ent/ent_base.hpp>

/**
 * @brief Namespace del core del Motor
 *
 */
namespace Moon::Core {
    /**
     * @brief Clase de la que hereda cada entity del Motor
     * \image html assets/stability/stability_2.png
     * @tparam Type
     */
    template<class Type>
    struct Entity_t : public EntityBase_t
    {
        /**ID de la Entity*/
        Moon::Alias::EntityId eid = 0;

        /**
         * @brief Construct a new Entity_t object
         *
         */
        Entity_t();

        /**
         * @brief Construct a new Entity_t object
         *
         * @param eid
         */
        Entity_t(Moon::Alias::EntityId eid);

        /**
         * @brief Destroy the Entity_t object
         *
         */
        virtual ~Entity_t() = 0;

        /**
         * @brief Get the Entity Type object
         *
         * @return Moon::Alias::EntityType
         */
        static Moon::Alias::EntityType getEntityType() noexcept;


        void updateComponent(Moon::Alias::ComponentType cid, ComponentBase_t* cmp_ptr){
            auto it = this->components.find(cid);
            if(it != this->components.end()){
                it->second = cmp_ptr;
            }
        }

        auto begin() {return this->components.begin();}
        auto end() {return this->components.end();}
    };

} // namespace Moon::Core