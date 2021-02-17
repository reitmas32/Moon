#pragma once

#include <lib/miniwin/include/miniwin.h>

#include "../../lib/Moon/template/sys/sys.tpp"

#include "../cmp/physics_cmp.hpp"
#include "../cmp/sprite_board_cmp.hpp"
#include "../cmp/sprite_piece_cmp.hpp"
#include "../ent/piece_ent.hpp"
#include "../gtx/board_gtx.hpp"
#include "../gtx/piece_gtx.hpp"

struct RenderSys : Moon::Core::System_t<PieceGtx_t, BoardGtx_t>
{
    void update(PieceGtx_t* piece_gtx, BoardGtx_t* board_gtx) override
    {
        for (auto& cmp : piece_gtx->getComponents<PhysicsCmp_t>()) {
            const auto* sprite_cmp = piece_gtx->getEntityById(cmp.eid)
                                       ->getComponent<SpritePieceCmp_t>();
            miniwin::color(sprite_cmp->color);
            miniwin::rectangulo_lleno(cmp.orig.x * 25,
                                      cmp.orig.y * 25,
                                      cmp.orig.x * 25 + 25,
                                      cmp.orig.y * 25 + 25);
            for (auto cord : cmp.perif) {
                miniwin::rectangulo_lleno((cmp.orig.x + cord.x) * 25,
                                          (cmp.orig.y + cord.y) * 25,
                                          (cmp.orig.x + cord.x) * 25 + 25,
                                          (cmp.orig.y + cord.y) * 25 + 25);
            }
        }

        for (auto& cmp : board_gtx->getComponents<SpriteBoardCmp_t>()) {

            for (int i = 0; i < COLUMNS; i++) {
                for (size_t j = 0; j < ROWS; j++) {
                    // miniwin::color(miniwin::NEGRO);
                    if (cmp.boxes[(i * ROWS) + j]) {
                        miniwin::color(miniwin::BLANCO);
                        miniwin::rectangulo_lleno(
                          j * 25, i * 25, j * 25 + 25, i * 25 + 25);
                    }
                }
            }
        }
        miniwin::refresca();
    }
    bool alive() override { return true; }
};