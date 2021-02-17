#pragma once

#include "../../lib/Moon/template/ent/ent.tpp"

struct PieceEnt_t : public Moon::Core::Entity_t<PieceEnt_t>
{

    PieceEnt_t(Moon::Alias::EntityId eid)
      : Moon::Core::Entity_t<PieceEnt_t>(eid)
    {}

    //~PieceEnt_t() override {}
};
