/**
 * @file component_vect.hpp
 * @author Oswaldo Rafael Zamora Ramírez (rafa.zamo.rals@comunidad.unam.mx)
 * @brief Wrapper de un Vector de Components
 * @version 0.1
 * @date 2020-08-03
 *
 * @copyright Copyright (c) Moon 2020 Oswaldo Rafael Zamora Ramírez
 *
 */
#pragma once

// std::vector
#include <vector>

#include <core/concepts.hpp>

#include <optional>

#include <functional>


/**
 * @brief Namespace del core del Motor
 *
 */
namespace Moon::Core {
    /**
     * @brief Wrapper de un Vector de Components
     * \image html assets/stability/stability_2.png
     */
    struct ComponentBaseVect_t
    {
        /**
         * @brief Destructor de ComponentBaseVect_t object
         *
         */
        virtual ~ComponentBaseVect_t() = default;
        virtual ComponentBase_t* deleteComponentByEntityId(Moon::Alias::EntityId eid) = 0;
    };

    /**
     * @brief Wrapper de un Vector de Components especificos
     *
     * @tparam CMP_t
     */
    template<Moon::Concepts::Cmp_t CMP_t>
    struct ComponentVect_t : ComponentBaseVect_t
    {
        // vector encapsulado
        std::vector<CMP_t> components;

        constexpr auto findComponentIteratorById(Moon::Alias::EntityId eid) noexcept{
            std::optional itopt =
                std::find_if(components.begin(), components.end(), 
                    [&eid](CMP_t& cmp){return cmp.eid == eid; }
                );
            if (*itopt == components.end()) itopt.reset();

            return itopt;
        }

        ComponentBase_t* deleteComponentByEntityId(Moon::Alias::EntityId eid) override final{
            auto itopt = this->findComponentIteratorById(eid);

            if(!itopt) return nullptr;

            auto it = *itopt;

            if( it + 1 != components.end())
                *it = components.back();
            components.pop_back();

            return it.base();
        }
    };
} // namespace Moon::Core
