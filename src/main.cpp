#include <iostream>
#include <chrono>
#include <thread>
#include <termios.h>
namespace Ncurses
{
#include <ncurses.h>
} // namespace Ncurses

#include "../lib/moon/template/cmp/cmp.tpp"
//#include "../lib/moon/template/cmp/cmp_base.tpp"
#include "../lib/moon/template/ent/ent.tpp"
#include "../lib/moon/template/ent/ent_base.tpp"

#include "../lib/moon/template/gtx/gtx.tpp"
#include "../lib/moon/template/cmp/cmp_storage.tpp"
#include "../lib/moon/template/sys/sys.tpp"

static struct termios old, other;

/* Initialize other terminal i/o settings */
void initTermios(int echo)
{
    tcgetattr(0, &old);                   //grab old terminal i/o settings
    other = old;                          //make other settings same as old settings
    other.c_lflag &= ~ICANON;             //disable buffered i/o
    other.c_lflag &= echo ? ECHO : ~ECHO; //set echo mode
    tcsetattr(0, TCSANOW, &other);        //apply terminal io settings
}

/* Restore old terminal i/o settings */
void resetTermios(void)
{
    tcsetattr(0, TCSANOW, &old);
}

static void gotoxy(short x, short y)
{
    printf("%c[%d;%df", 0x1B, y, x);
}

struct Sprite_t : public Moon::Core::Component_t<Sprite_t>
{
public:
    Sprite_t(Moon::Alias::EntityId eid) : Moon::Core::Component_t<Sprite_t>(eid) {}
    char sprite;
    short x{0}, y{0};
};

struct Pacman : Moon::Core::Entity_t<Pacman>
{
    //Pacman()
    //{
    //}
    explicit Pacman(Moon::Alias::EntityId eid) : Moon::Core::Entity_t<Pacman>(eid) {}
    //~Pacman()
    //{
    //}
};

struct GtxPacman : Moon::Core::GameContext_t<Pacman>
{
};

struct RenderSys : Moon::Core::System_t<GtxPacman>
{
    bool alive_flag = true;
    RenderSys() {}

    ~RenderSys() {}

    bool alive() { return alive_flag; }

    void update(GtxPacman *g_pacman)
    {
        for (auto &cmp : g_pacman->getComponents<Sprite_t>())
        {
            gotoxy(cmp.x, cmp.y);
            std::puts(static_cast<const char *>(&cmp.sprite));
            //std::cout << "cmp.sprite";
            //std::printf("%c", cmp.sprite);
            //std::printf("Sprite: %c, in (%u, %u)\n", cmp.sprite, cmp.x, cmp.y);
        }
    }
};

struct InputSys : Moon::Core::System_t<RenderSys>
{
    InputSys()
    {
        Ncurses::initscr();
        Ncurses::cbreak();
        Ncurses::noecho();
        Ncurses::scrollok(Ncurses::stdscr, TRUE);
        Ncurses::nodelay(Ncurses::stdscr, TRUE);
    }

    ~InputSys() {}

    bool alive() { return true; }

    void update(RenderSys *g_pacman)
    {
        //for (auto &cmp : g_pacman->getComponents<Sprite_t>())
        //{
        //    gotoxy(cmp.x, cmp.y);
        //    std::puts(static_cast<const char *>(&cmp.sprite));
        //    //std::cout << "cmp.sprite";
        //    //std::printf("%c", cmp.sprite);
        //    //std::printf("Sprite: %c, in (%u, %u)\n", cmp.sprite, cmp.x, cmp.y);
        //}
        if (Ncurses::wgetch(Ncurses::stdscr) == 'a')
        {
            g_pacman->alive_flag = false;
        }
    }
};

int main(int argc, char const *argv[])
{
    GtxPacman gtx_pacman = GtxPacman();
    RenderSys rend_sys = RenderSys();
    InputSys input_sys = InputSys();
    auto &p1 = gtx_pacman.addEntity();
    auto &p2 = gtx_pacman.addEntity();
    auto &p3 = gtx_pacman.addEntity();

    gtx_pacman.addComponentById<Sprite_t>(p1.eid);
    gtx_pacman.addComponentById<Sprite_t>(p2.eid);
    gtx_pacman.addComponentById<Sprite_t>(p3.eid);

    p1.getComponent<Sprite_t>()->sprite = '@';
    p2.getComponent<Sprite_t>()->sprite = '#';
    p3.getComponent<Sprite_t>()->sprite = '&';

    p1.getComponent<Sprite_t>()->x = 1;
    p2.getComponent<Sprite_t>()->x = 10;
    p3.getComponent<Sprite_t>()->x = 14;

    p1.getComponent<Sprite_t>()->y = 5;
    p2.getComponent<Sprite_t>()->y = 6;
    p3.getComponent<Sprite_t>()->y = 10;
    using namespace std::chrono_literals;
    while (rend_sys.alive())
    {
        std::puts("\033[H\033[J");
        rend_sys.update(&gtx_pacman);
        input_sys.update(&rend_sys);
        std::this_thread::sleep_for(33ms);
    }
    //gotoxy(4, 4);
    //std::printf("Hola\n");

    return 0;
}
