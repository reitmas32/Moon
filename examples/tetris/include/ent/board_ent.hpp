#pragma once

#include <lib/Moon/template/ent/ent.tpp>

struct BoardEnt_t : Moon::Core::Entity_t<BoardEnt_t>
{

    BoardEnt_t(Moon::Alias::EntityId eid)
      : Moon::Core::Entity_t<BoardEnt_t>(eid)
    {}

    ~BoardEnt_t() override {}
};