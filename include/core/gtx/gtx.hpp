/**
 * @file game_context.hpp
 * @author Oswaldo Rafael Zamora Ramírez (rafa.zamo.rals@comunidad.unam.mx)
 * @brief Clase GameContext !!! Es laencargada de alamacenar Los datos de las
 * Entity y los Components
 * @version 1.2.0
 * @date 2021-03-03
 *
 * @copyright Copyright (c) Moon 2020-2021 Oswaldo Rafael Zamora Ramírez
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

#include <core/ent/ent_storage.tpp>

/**
 * @include moon_log.hpp
 */
#include <tools/moon_log.hpp>

// Numero de Entity que tendra cada GameContext
//#define NUM_ENTITIES 100

/**
 * @brief Namespace del core del Motor
 *
 */
namespace Moon::Core
{
    /**
     * @subsubsection Example
     * @code{.cpp}
     * struct Gtx_t : Moon::Core::GameContext_t<Gtx_t>
     * {
     *     Gtx_t();
     *     ~Gtx_t();
     * };
     * 
     * //Use Gtx_t
     * 
     * //Create
     * auto gtx = Gtx_t();
     * 
     * //Add Entities
     * auto ent_1 = gtx.addEntity<Triangle_t>();
     * auto ent_2 = gtx.addEntity<Triangle_t>();
     * auto ent_3 = gtx.addEntity<Triangle_t>();
     * 
     * //Add Cmp to ent_1
     * gtx.addComponentById<Triangle_t, SpriteTriangle_t>(ent_1.eid, 0.2f);
     * gtx.addComponentById<Triangle_t, Position2Df_t>(ent_1.eid, 0.0f, 0.0f);
     * gtx.addComponentById<Triangle_t, PhysicsCmp_t>(ent_1.eid, true);
     * 
     * //Add Cmp to ent_2
     * gtx.addComponentById<Triangle_t, SpriteTriangle_t>(ent_2.eid, 0.15f);
     * gtx.addComponentById<Triangle_t, Position2Df_t>(ent_2.eid, 0.9f, -0.9f);
     * gtx.addComponentById<Triangle_t, IACmp_t>(ent_2.eid);
     * 
     * //Add Cmp to ent_3
     * gtx.addComponentById<Triangle_t, SpriteTriangle_t>(ent_3.eid, 0.1f);
     * gtx.addComponentById<Triangle_t, Position2Df_t>(ent_3.eid, -0.5f, -0.5f);
     * gtx.addComponentById<Triangle_t, RotateCmp_t>(ent_3.eid);
     * 
     * //Game Loop
     * 
     * while(...){
     *      .
     *      .
     *      .
     *      physicsSys.update(&gtx);
     *      renderSys.update(&gtx);
     *      inputSys.update();
     *      .
     *      .
     *      .
     * }
     * 
     * //In Updates of Systems
     * struct PhysicsSys_t : Moon::Core::System_t<Gtx_t>{
     *      void update(Gtx_t *gtx) override{
     *          for (Position2Df_t &cmp : gtx->getComponents<Position2Df_t>())
     *           {
     *               //Any Update cmp Physics
     *           }
     *      }
     * };
     * @endcode
     */
    /**
     * @brief Clase GameContext !!! Es laencargada de alamacenar Los datos de
     * las ENtity y los Components
     * @image html assets/stability/stability_2.png
     * @tparam Type
     */
    template <typename Type>
    struct GameContext_t : public GameContextBase_t
    {
        /**Vector de entities*/
        EntityStorage_t entities;

        /**Almacenamiento de los Compnnets*/
        ComponentStorage_t components;

        /**
         * @brief Contructor de GameContext_t object
         *
         */
        //TODO:LOGS
        GameContext_t()
        {
            Moon::Tools::Logs::contructor("GameContext_t", this);
        }

        /**
         * @brief Destructor de GameContext_t object
         *
         */
        //TODO:LOGS
        virtual ~GameContext_t()
        {
            Moon::Tools::Logs::destructor("GameContext_t", this);
        }

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
        template <typename ENT_t, typename... Ts>
        ENT_t &addEntity(Ts &&...args)
        {
            auto &ent = this->entities.template createEntity<ENT_t>(this->nextId++, args...);
            return ent;
        }

        /**
         * @brief Get the Entity By Id object
         *
         * @param eid
         * @return Type*
         */

        template <typename ENT_t>
        ENT_t *getEntityById(Moon::Alias::EntityId eid)
        {
            auto it = std::find_if(this->entities.template getEntities<ENT_t>().begin(),
                                   this->entities.template getEntities<ENT_t>().end(),
                                   [&](ENT_t &e) { return eid == e.eid; });
            if (it == this->entities.template getEntities<ENT_t>().end())
            {
                return nullptr;
            }
#ifdef MOON_WINDOWS_CLANG
            return &(*it);
#else
            return it.base();
#endif
        }
        /**
         * @brief Añade un nuevo component a la entity señalada
         *
         * @tparam Cmp_t
         * @param eid
         * @return Cmp_t&
         */

        template <typename ENT_t, MOON_IS_CMP_T CMP_t, typename... Ts>
        CMP_t &addComponentById(Moon::Alias::EntityId eid, Ts &&...args)
        {
            ENT_t *e = this->getEntityById<ENT_t>(eid);
            auto &cmp =
                this->components.template createComponent<CMP_t>(eid, args...);
            e->template addComponent<CMP_t>(&cmp);
            return cmp;
        }
        /**
         * @brief Get the Components
         *
         * @tparam CMP_t
         * @return std::vector<CMP_t>&
         */

        template <MOON_IS_CMP_T CMP_t>
        std::vector<CMP_t> &getComponents()
        {
            return this->components.template getComponents<CMP_t>();
        }

        /**
         * @brief Get the Entities
         *
         * @tparam ENT_t 
         * @return std::vector<ENT_t>&
         */
        template <typename ENT_t>
        std::vector<ENT_t> &getEntities()
        {
            return this->entities.template getEntities<ENT_t>();
        }

        /**
         * @brief Delete the Entitie
         *
         * @tparam ENT_t 
         * @param eid if of Entity
         */
        template <typename ENT_t>
        void destroyEntityById(Moon::Alias::EntityId eid)
        {
            auto *entity{this->getEntityById<ENT_t>(eid)};
            if (!entity)
                return;

            for (auto &[typeID, _] : *entity)
            {
                auto *cmp_ptr = this->components.deleteComponentByTypeIdAndEntityId(typeID, eid);
                if (!cmp_ptr)
                    continue;

                auto *moveEntity{this->getEntityById<ENT_t>(cmp_ptr->eid)};

                if (moveEntity)
                {
                    moveEntity->updateComponent(typeID, cmp_ptr);
                }
            }
            auto it = std::find_if(this->entities.template getEntities<ENT_t>().begin(), this->entities.template getEntities<ENT_t>().end(),
                                   [&](const auto &e) { return e.eid == eid; });
            this->entities.template getEntities<ENT_t>().erase(it);
            std::cout << "Muerte " << eid << '\n';
        }

        /**
         * @brief Get the Component
         *
         * @tparam CMP_t 
         * @param eid if of Entity
         */
        template <MOON_IS_CMP_T CMP_t>
        CMP_t *getRequiredComponent(Moon::Alias::EntityId eid)
        {
            auto &vectCmps = this->template getComponents<CMP_t>();
            auto it = std::find_if(vectCmps.begin(),
                                   vectCmps.end(),
                                   [&](CMP_t &cmp) { return eid == cmp.eid; });
            if (it == vectCmps.end())
            {
                return nullptr;
            }
#ifdef MOON_WINDOWS_CLANG
            return &(*it);
#elif defined(MOON_WINDOWS_CYGWIN) || defined(MOON_PLATFORM_LINUX)
            return it.base();
#else
            return nullptr;
#endif
        }
    };

} // namespace Moon::Core