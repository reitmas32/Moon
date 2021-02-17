#pragma once

#include <vector>

#include "../../lib/Moon/template/cmp/cmp.tpp"

#include "../util/coordinate.hpp"

struct PhysicsCmp_t : public Moon::Core::Component_t<PhysicsCmp_t>
{
    Coodinate_t orig;
    std::vector<Coodinate_t> perif;

    Coodinate_t prev_orig;

    bool flag_new = true;

    PhysicsCmp_t() {}

    PhysicsCmp_t(Moon::Alias::EntityId eid)
      : Moon::Core::Component_t<PhysicsCmp_t>(eid)
    {}

    explicit PhysicsCmp_t(Moon::Alias::EntityId eid,
                          Coodinate_t orig,
                          std::vector<Coodinate_t> perif)
      : Moon::Core::Component_t<PhysicsCmp_t>(eid)
      , orig{ orig }
      , prev_orig{ orig }
      , perif{ perif }
    {}

    void rota()
    {
        for (auto& cord : this->perif) {
            cord.rota();
        }
    }

    Coodinate_t position(int n)
    {
        Coodinate_t ret;
        if (n == 0) {
            ret.x = this->orig.x;
            ret.y = this->orig.y;
        } else {
            ret.x = this->orig.x + this->perif[n - 1].x;
            ret.y = this->orig.y + this->perif[n - 1].y;
        }
        return ret;
    }

    void prev() { this->orig = this->prev_orig; }

    ~PhysicsCmp_t() override {}
};