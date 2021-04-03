/**
 * @file entity_base.hpp
 * @author Oswaldo Rafael Zamora Ramirez (rafa.zamo.rals@comunidad.unam.mx)
 * @version 0.0.1
 * @date 2020-08-03
 *
 * @copyright Copyright (c) Moon 2020 Oswaldo Rafael Zamora Ramírez
 *
 */
#pragma once

/**
 * \include alias.hpp
 */
#include <core/alias.hpp>

/**
 * \include cmp/cmp_base.hpp
 */
#include <core/cmp/cmp_base.hpp>

#include <tools/moon_log.hpp>

/**
 * @brief Namespace of the Core the Moon
 * \namespace Moon::Core
 */
namespace Moon::Core
{
  /** Redefinition of a vector of Types and Components*/
  using MapCmps_t =
      std::unordered_map<Moon::Alias::ComponentType, ComponentBase_t *>;

  /**
     * @brief Class from which any entity of the Engine inherits
     * \image html assets/stability/stability_2.png
     */
  struct EntityBase_t
  {

    /**Identifier of the following type of Entity_t*/
    inline static Moon::Alias::EntityType nextType = 0;

    /** Map of Types and Components*/
    MapCmps_t components;

  public:
    /** Construct Default*/
    EntityBase_t()
    {
      Moon::Tools::Logs::contructor("EntityBase_t", this);
    }

    /** Destroy the EntityBase_t object is virtual*/
    virtual ~EntityBase_t()
    {
      Moon::Tools::Logs::destructor("EntityBase_t", this);
    }

    /**
         * @brief Add a Component_t
         *
         * @tparam CMP_t Type of the Component_t
         * @pre CMP_t is base of Moon::Core::ComponentBase_t
         * @param cmp pointer of Component_t
         */
    template <class CMP_t>
    requires std::is_base_of<Moon::Core::ComponentBase_t, CMP_t>::value void
    addComponent(CMP_t *cmp);

    /**
         * @brief Get the Component
         *
         * @tparam CMP_t
         * @pre CMP_t is base of Moon::Core::ComponentBase_t
         * @return CMP_t*
         */
    template <class CMP_t>
    requires std::is_base_of<Moon::Core::ComponentBase_t, CMP_t>::value
        CMP_t *
        getComponent();
  };

} // namespace Moon::Core