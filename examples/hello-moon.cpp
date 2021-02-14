#include "../template/cmp/cmp.tpp"
#include "../template/cmp/cmp_storage.tpp"
#include "../template/ent/ent.tpp"
#include "../template/ent/ent_base.tpp"
#include "../template/gtx/gtx.tpp"
#include "../template/sys/sys.tpp"

#include <chrono>
#include <iostream>
#include <ncurses.h>
#include <thread>

#define ESC_KEY 27

static void gotoxy(short x, short y) { printf("%c[%d;%df", 0x1B, y, x); }

struct Sprite_t : Moon::Core::Component_t<Sprite_t> {
  char sprite;
  int x, y;

  Sprite_t() {}

  Sprite_t(Moon::Alias::EntityId eid)
      : Moon::Core::Component_t<Sprite_t>(eid) {}

  explicit Sprite_t(Moon::Alias::EntityId eid, char sprite, int x, int y)
      : Moon::Core::Component_t<Sprite_t>(eid), sprite{sprite}, x{x}, y{y} {}

  ~Sprite_t() override {}
};

struct MyEntity_t : public Moon::Core::Entity_t<MyEntity_t> {
  explicit MyEntity_t(Moon::Alias::EntityId eid)
      : Moon::Core::Entity_t<MyEntity_t>(eid) {}
};

struct GameContextOfMyEentity_t : Moon::Core::GameContext_t<MyEntity_t> {};

struct RenderSystem_t : Moon::Core::System_t<GameContextOfMyEentity_t> {
  void update(GameContextOfMyEentity_t *gtx_my_entity_t) override {

    for (auto &&cmp : gtx_my_entity_t->getComponents<Sprite_t>()) {
      gotoxy(cmp.x, cmp.y);
      std::puts(static_cast<const char *>(&cmp.sprite));
    }
  }

  bool alive() override { return true; }

  ~RenderSystem_t() override {}
};

struct InputSys : Moon::Core::System_t<RenderSystem_t> {

  bool alive_flag{true};

  InputSys() {
    initscr();
    cbreak();
    noecho();
    scrollok(stdscr, TRUE);
    nodelay(stdscr, TRUE);
  }
  ~InputSys() override {}

  bool alive() override { return this->alive_flag; }

  void update(RenderSystem_t *render_sys_t) override {
    if (wgetch(stdscr) == ESC_KEY) {
      this->alive_flag = false;
    }
  }
};

int main() {
  auto my_gtx = GameContextOfMyEentity_t();
  auto my_render_sys = RenderSystem_t();
  auto input_sys = InputSys();

  auto &ent_1 = my_gtx.addEntity();
  auto &ent_2 = my_gtx.addEntity();
  auto &ent_3 = my_gtx.addEntity();

  my_gtx.addComponentById<Sprite_t>(ent_1.eid, 'a', 1, 6);
  my_gtx.addComponentById<Sprite_t>(ent_2.eid, '@', 5, 3);
  my_gtx.addComponentById<Sprite_t>(ent_3.eid, '#', 10, 8);

  using namespace std::chrono_literals;
  while (input_sys.alive()) {
    std::puts("\033[H\033[J");
    my_render_sys.update(&my_gtx);
    input_sys.update(&my_render_sys);
    std::this_thread::sleep_for(33ms);
  }
  endwin();

  return 0;
}