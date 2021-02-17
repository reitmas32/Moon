#pragma once

#include "../../lib/Moon/template/cmp/cmp.tpp"

struct InputCmp_t : Moon::Core::Component_t<InputCmp_t>
{
    bool UP, DOWN, LEFT, RIGTH;
    InputCmp_t() {}

    explicit InputCmp_t(Moon::Alias::EntityId eid)
      : Moon::Core::Component_t<InputCmp_t>(eid)
    {}

    void reset()
    {
        this->UP = false;
        this->DOWN = false;
        this->RIGTH = false;
        this->LEFT = false;
    }
};