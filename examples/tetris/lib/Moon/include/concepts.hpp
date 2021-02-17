#pragma once

#include <concepts>

#include "cmp/cmp_base.hpp"
#include "ent/ent_base.hpp"
#include "gtx/gtx_base.hpp"
#include "sys/sys_base.hpp"

namespace Moon::Concepts {
    template<typename Gtx_t>
    concept Ctx_t =
      std::is_base_of<Moon::Core::GameContextBase_t, Gtx_t>::value ||
      std::is_base_of<Moon::Core::SystemBase_t, Gtx_t>::value;

    template<typename Entity_t>
    concept Ent_t = std::is_base_of<Moon::Core::EntityBase_t, Entity_t>::value;

    template<typename Component_t>
    concept Cmp_t =
      std::is_base_of<Moon::Core::ComponentBase_t, Component_t>::value;
} // namespace Moon::Concepts
