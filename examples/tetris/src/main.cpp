
#include <lib/miniwin/include/miniwin.h>

#include "../include/cmp/physics_cmp.hpp"
#include "../include/cmp/sprite_piece_cmp.hpp"

#include <chrono>
#include <thread>

#include "../lib/Moon/template/cmp/cmp_storage.tpp"
#include "../lib/Moon/template/ent/ent.tpp"
#include "../lib/Moon/template/ent/ent_base.tpp"
#include "../lib/Moon/template/gtx/gtx.tpp"
#include "../lib/Moon/template/sys/sys.tpp"

#include "../include/cmp/input_cmp.hpp"
#include "../include/cmp/physics_cmp.hpp"
#include "../include/cmp/sprite_board_cmp.hpp"
#include "../include/cmp/sprite_piece_cmp.hpp"

#include "../include/ent/board_ent.hpp"
#include "../include/ent/piece_ent.hpp"

#include "../include/gtx/board_gtx.hpp"
#include "../include/gtx/piece_gtx.hpp"

#include "../include/sys/collapse_sys.hpp"
#include "../include/sys/collision_sys.hpp"
#include "../include/sys/input_sys.hpp"
#include "../include/sys/phisics_sys.hpp"
#include "../include/sys/render_sys.hpp"

struct RandomPieceSys_t : Moon::Core::System_t<PieceGtx_t>
{

    constexpr static Coodinate_t perifs[7][3]{
        { { 1, 0 }, { 0, 1 }, { 1, 1 } },   // Cuadrado
        { { 1, 0 }, { -1, 1 }, { 0, 1 } },  // S
        { { 0, 1 }, { 1, 1 }, { -1, 0 } },  // 2
        { { 0, 1 }, { 0, -1 }, { 1, 1 } },  // L
        { { 0, 1 }, { 0, -1 }, { -1, 1 } }, // J
        { { 0, 1 }, { 0, -1 }, { 0, 2 } },  // I
        { { -1, 0 }, { 1, 0 }, { 0, 1 } }   // T
    };

    bool alive() override { return true; }

    void update(PieceGtx_t* piece_gtx) override
    {
        for (auto& cmp : piece_gtx->getComponents<PhysicsCmp_t>()) {
            if (cmp.flag_new) {
                int r = 1 + rand() % 7;
                for (size_t i = 0; i < 3; i++) {
                    cmp.perif[i] = { RandomPieceSys_t::perifs[r][i].x,
                                     RandomPieceSys_t::perifs[r][i].y };
                }
                cmp.orig = Coodinate_t{ 5, 2 };
                cmp.prev_orig = Coodinate_t{ 5, 2 };
                cmp.flag_new = false;
            }
        }
    }
};

int
main()
{
    srand(time(0));
    miniwin::vredimensiona(ROWS * 25, COLUMNS * 25);
    auto piece_gtx = PieceGtx_t();
    auto render_sys = RenderSys();
    auto input_sys = InputSys_t();
    auto physics_sys = PhysicsSys_t();
    auto collison_sys = CollisionSys_t();
    auto collapse_sys = CollapseSys_t();
    auto random_piece_sys = RandomPieceSys_t();

    auto& e1 = piece_gtx.addEntity();
    piece_gtx.addComponentById<SpritePieceCmp_t>(e1.eid, miniwin::ROJO);
    piece_gtx.addComponentById<PhysicsCmp_t>(
      e1.eid,
      Coodinate_t{ 5, 2 },
      std::vector<Coodinate_t>{ { 1, 0 }, { 0, 1 }, { 1, 1 } });
    piece_gtx.addComponentById<InputCmp_t>(e1.eid);

    auto board_gtx = BoardGtx_t();

    auto& board = board_gtx.addEntity();
    auto& sprite_board =
      board_gtx.addComponentById<SpriteBoardCmp_t>(board.eid);

    using namespace std::chrono_literals;
    while (input_sys.alive()) {
        miniwin::borra();
        input_sys.update(&piece_gtx);
        physics_sys.update(&piece_gtx);
        collison_sys.update(&piece_gtx, &board_gtx);
        collapse_sys.update(&board_gtx);
        random_piece_sys.update(&piece_gtx);
        render_sys.update(&piece_gtx, &board_gtx);
        std::this_thread::sleep_for(16ms);
    }
    miniwin::refresca();
    miniwin::vcierra();

    return 0;
}
