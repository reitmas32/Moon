#pragma once

#include <lib/Moon/template/sys/sys.tpp>

#include "../cmp/sprite_board_cmp.hpp"
#include "../gtx/board_gtx.hpp"

struct CollapseSys_t : Moon::Core::System_t<BoardGtx_t>
{
    bool alive() override { return true; }

    void update(BoardGtx_t* board_gtx) override
    {
        for (auto& cmp : board_gtx->getComponents<SpriteBoardCmp_t>()) {

            int fila = COLUMNS - 1;
            while (fila >= 0) {
                if (cmp.fullColumn(fila)) {
                    cmp.collaps(fila);
                } else {
                    fila--;
                }
            }
        }
    }
};