#pragma once

#include "../../lib/Moon/template/sys/sys.tpp"

#include "../cmp/input_cmp.hpp"
#include "../cmp/physics_cmp.hpp"
#include "../ent/piece_ent.hpp"
#include "../gtx/piece_gtx.hpp"

struct PhysicsSys_t : Moon::Core::System_t<PieceGtx_t>
{

    const static std::uint8_t down_time_const{ 50 };
    inline static std::uint8_t down_time_iter{ 0 };

    bool alive() override { return true; }

    void update(PieceGtx_t* piece_gtx) override
    {
        for (auto& cmp : piece_gtx->getComponents<PhysicsCmp_t>()) {
            const auto* inp_cmp =
              piece_gtx->getEntityById(cmp.eid)->getComponent<InputCmp_t>();
            cmp.prev_orig = cmp.orig;
            if (inp_cmp) {

                if (inp_cmp->UP)
                    // cmp.orig.y -= 1;
                    cmp.rota();
                if (inp_cmp->DOWN)
                    cmp.orig.y += 1;
                if (inp_cmp->LEFT)
                    cmp.orig.x -= 1;
                if (inp_cmp->RIGTH)
                    cmp.orig.x += 1;
                if (PhysicsSys_t::down_time_iter ==
                    PhysicsSys_t::down_time_const) {
                    cmp.orig.y += 1;
                    PhysicsSys_t::down_time_iter = 0;
                }
            }
            ++PhysicsSys_t::down_time_iter;
        }
    }
};