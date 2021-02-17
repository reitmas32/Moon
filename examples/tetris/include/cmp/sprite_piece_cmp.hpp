#pragma once

#include <vector>

#include "../../lib/Moon/template/cmp/cmp.tpp"

struct SpritePieceCmp_t : Moon::Core::Component_t<SpritePieceCmp_t>
{
    int color;

    SpritePieceCmp_t() {}

    SpritePieceCmp_t(Moon::Alias::EntityId eid)
      : Moon::Core::Component_t<SpritePieceCmp_t>(eid)
    {}

    explicit SpritePieceCmp_t(Moon::Alias::EntityId eid, int color)
      : Moon::Core::Component_t<SpritePieceCmp_t>(eid)
      , color{ color }
    {}

    ~SpritePieceCmp_t() override {}
};