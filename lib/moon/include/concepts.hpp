#pragma once

#include <concepts>

#include "gtx/gtx_base.hpp"
#include "sys/sys_base.hpp"
#include "ent/ent_base.hpp"

namespace Moon::Concepts
{
    template <typename Gtx_t>
    concept Ctx_t = std::is_base_of<Moon::Core::GameContextBase_t, Gtx_t>::value || std::is_base_of<Moon::Core::SystemBase_t, Gtx_t>::value;
} // namespace Moon::Concepts
