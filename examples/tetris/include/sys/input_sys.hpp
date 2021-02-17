#pragma once

#include <lib/miniwin/include/miniwin.h>

#include "../../lib/Moon/template/sys/sys.tpp"

#include "../cmp/input_cmp.hpp"
#include "../cmp/physics_cmp.hpp"
#include "../ent/piece_ent.hpp"
#include "../gtx/piece_gtx.hpp"

struct InputSys_t : Moon::Core::System_t<PieceGtx_t>
{
    bool alive_flag = true;

    bool alive() override { return this->alive_flag; }

    void update(PieceGtx_t* piece_gtx) override
    {
        int tecla = miniwin::tecla();

        for (auto& cmp : piece_gtx->getComponents<InputCmp_t>()) {
            cmp.reset();
            switch (tecla) {
                case miniwin::ARRIBA:
                    cmp.UP = true;
                    break;
                case miniwin::ABAJO:
                    cmp.DOWN = true;
                    break;
                case miniwin::DERECHA:
                    cmp.RIGTH = true;
                    break;
                case miniwin::IZQUIERDA:
                    cmp.LEFT = true;
                    break;
                default:
                    break;
            }
        }
        tecla == miniwin::ESCAPE ? this->alive_flag = false
                                 : this->alive_flag = true;
    }
};