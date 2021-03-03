/**
 * @file game_context.hpp
 * @author Oswaldo Rafael Zamora Ramírez (rafa.zamo.rals@comunidad.unam.mx)
 * @brief Clase GameContext !!! Es laencargada de alamacenar Los datos de las
 * ENtity y los Components
 * @version 0.1
 * @date 2020-08-03
 *
 * @copyright Copyright (c) Moon 2020 Oswaldo Rafael Zamora Ramírez
 *
 */
#pragma once

// std::vector
#include <vector>

// std::find
#include <algorithm>

// Alias
#include <core/alias.hpp>

#include <core/concepts.hpp>

// GameContxtBase
#include <core/gtx/gtx_base.hpp>

// ComponentStorage
#include <core/cmp/cmp_storage.hpp>

// Numero de Entity que tendra cada GameContext
#define NUM_ENTITIES 100

/**
 * @brief Namespace del core del Motor
 *
 */
namespace Moon::Core {
    /**
     * @brief Clase GameContext !!! Es laencargada de alamacenar Los datos de
     * las ENtity y los Components
     * \image html assets/stability/stability_2.png
     * @tparam Type
     */
    template<Moon::Concepts::Ent_t Type>
    struct GameContext_t : public GameContextBase_t
    {
        /**Vector de entities*/
        std::vector<Type> entities;

        /**Almacenamiento de los Compnnets*/
        ComponentStorage_t components;

        /**
         * @brief Contructor de GameContext_t object
         *
         */
        GameContext_t();

        /**
         * @brief Destructor de GameContext_t object
         *
         */
        virtual ~GameContext_t() = 0;

        /**
         * @brief Get the Game Context Type object
         *
         * @return Moon::Alias::GameContextType
         */
        static Moon::Alias::GameContextType getGameContextType() noexcept;

        /**
         * @brief Añade una nueva entity
         *
         * @return Type&
         */
        Type& addEntity();

        /**
         * @brief Get the Entity By Id object
         *
         * @param eid
         * @return Type*
         */
        Type* getEntityById(Moon::Alias::EntityId eid);

        /**
         * @brief Añade un nuevo component a la entity señalada
         *
         * @tparam Cmp_t
         * @param eid
         * @return Cmp_t&
         */
        template<Moon::Concepts::Cmp_t CMP_t, typename... Ts>
        CMP_t& addComponentById(Moon::Alias::EntityId eid, Ts&&... args)
        {
            Type* e = this->getEntityById(eid);
            auto& cmp =
              this->components.template createComponent<CMP_t>(eid, args...);
            e->template addComponent<CMP_t>(&cmp);
            return cmp;
        }

        /**
         * @brief Get the Components object
         *
         * @tparam CMP_t
         * @return std::vector<CMP_t>&
         */
        template<Moon::Concepts::Cmp_t CMP_t>
        std::vector<CMP_t>& getComponents()
        {
            return this->components.template getComponents<CMP_t>();
        }

        void destroyEntityById(Moon::Alias::EntityId eid){
            auto* entity { this->getEntityById(eid) };
            if( !entity ) return;

            for(auto& [typeID, _] : *entity){
                auto* cmp_ptr = this->components.deleteComponentByTypeIdAndEntityId(typeID, eid);
                if( !cmp_ptr ) continue;
                auto* moveEntity { this->getEntityById(cmp_ptr->eid)};

                moveEntity->updateComponent(typeID, cmp_ptr);
            }

            auto it = std::find_if(this->entities.begin(), this->entities.end(),
                [&](const auto& e){ return e.eid == eid;}
            );
            this->entities.erase(it);
            std::cout<<"Muerte" << eid<<'\n';
        }
    };

} // namespace Moon::Core