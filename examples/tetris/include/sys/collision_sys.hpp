#pragma once

#include <lib/Moon/template/sys/sys.tpp>

#include "../gtx/board_gtx.hpp"
#include "../gtx/piece_gtx.hpp"

#include "../ent/piece_ent.hpp"
#include "../gtx/piece_gtx.hpp"

#include "../cmp/physics_cmp.hpp"
#include "../cmp/sprite_board_cmp.hpp"
#include "../cmp/sprite_piece_cmp.hpp"

struct CollisionSys_t : Moon::Core::System_t<PieceGtx_t, BoardGtx_t>
{
    bool alive() override { return true; }

    void update(PieceGtx_t* piece_gtx, BoardGtx_t* board_gtx) override
    {
        for (auto& cmp : piece_gtx->getComponents<PhysicsCmp_t>()) {

            if (collisionBoard(cmp, board_gtx)) {
                for (auto& sprite_board_cmp :
                     board_gtx->getComponents<SpriteBoardCmp_t>()) {
                    sprite_board_cmp.addCoordinate(cmp.prev_orig.x,
                                                   cmp.prev_orig.y);
                    sprite_board_cmp.addCoordinate(
                      cmp.prev_orig.x + cmp.perif[0].x,
                      cmp.prev_orig.y + cmp.perif[0].y);
                    sprite_board_cmp.addCoordinate(
                      cmp.prev_orig.x + cmp.perif[1].x,
                      cmp.prev_orig.y + cmp.perif[1].y);
                    sprite_board_cmp.addCoordinate(
                      cmp.prev_orig.x + cmp.perif[2].x,
                      cmp.prev_orig.y + cmp.perif[2].y);
                    sprite_board_cmp
                      .boxes[cmp.prev_orig.y * ROWS + cmp.prev_orig.x] = true;
                    std::cout << "Colision al final\n";
                }
                cmp.flag_new = true;
            }
            if (this->collisionLimits(cmp, board_gtx)) {
                cmp.prev();
            }
        }
    }

    bool collisionLimits(PhysicsCmp_t& cmp, BoardGtx_t* board_gtx)
    {
        bool flag = false;
        for (int i = 0; i < 4; i++) {
            auto c = cmp.position(i);

            if (c.x < 0 || c.x >= ROWS) {
                flag = true;
            }

            if (c.y < 0 || c.y >= COLUMNS) {
                flag = true;
            }

            for (auto& sprite_board_cmp :
                 board_gtx->getComponents<SpriteBoardCmp_t>()) {
                if (sprite_board_cmp.boxes[c.y * ROWS + c.x])
                    flag = true;
            }
        }
        return flag;
    }

    bool collisionBoard(PhysicsCmp_t& cmp, BoardGtx_t* board_gtx)
    {
        bool flag = false;
        for (int i = 0; i < 4; i++) {
            auto c = cmp.position(i);
            if (c.y >= COLUMNS) {
                flag = true;
                return flag;
            }
            for (auto& sprite_board_cmp :
                 board_gtx->getComponents<SpriteBoardCmp_t>()) {
                if (sprite_board_cmp.boxes[c.y * ROWS + c.x] &&
                    cmp.orig.y > cmp.prev_orig.y) {
                    flag = true;
                }
            }
        }
        return flag;
    }
};