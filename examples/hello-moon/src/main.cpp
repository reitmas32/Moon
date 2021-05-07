//  src/main.cpp

#include <iostream>

//Info Platform
#include <Moon/include/tools/platform_info.hpp>

//Component
#include <Moon/template/core/cmp/cmp.tpp>
#include <Moon/template/core/cmp/cmp_storage.tpp>
#include <Moon/template/core/ent/ent_base.tpp>
#include <Moon/template/core/ent/ent.tpp>
#include <Moon/template/core/gtx/gtx.tpp>

//MyComponent
struct MyCmp_t : Moon::Core::Component_t<MyCmp_t>
{
    //data of Component
    int data;

    //Constructors
    MyCmp_t(Moon::Alias::EntityId eid) : Moon::Core::Component_t<MyCmp_t>(eid) {}
    MyCmp_t(
        Moon::Alias::EntityId eid,
        int data) : Moon::Core::Component_t<MyCmp_t>(eid), data{data}{}
    MyCmp_t() = default;

    //Destructors
    ~MyCmp_t() = default;   
};

struct MyCmp1_t : Moon::Core::Component_t<MyCmp1_t>
{
    //data of Component
    int data;

    //Constructors
    MyCmp1_t(Moon::Alias::EntityId eid) : Moon::Core::Component_t<MyCmp1_t>(eid) {}
    MyCmp1_t(
        Moon::Alias::EntityId eid,
        int data) : Moon::Core::Component_t<MyCmp1_t>(eid), data{data}{}
    MyCmp1_t() = default;

    //Destructors
    ~MyCmp1_t() = default;   
};

struct Player : Moon::Core::Entity_t<Player>
{
    Player(Moon::Alias::EntityId eid) : Moon::Core::Entity_t<Player>(eid) {}
    ~Player(){}
};

struct Gtx_t : Moon::Core::GameContext_t<Gtx_t>{

};

int main(int argc, char const *argv[])
{
    auto gtx = Gtx_t();
    auto & e1 = gtx.addEntity<Player>();
    auto & e2 = gtx.addEntity<Player>();
    auto &c1 = gtx.addComponentById<Player, MyCmp_t>(e1.eid, 5);
    auto &c3 = gtx.addComponentById<Player, MyCmp1_t>(e1.eid, 1);
    auto &c2 = gtx.addComponentById<Player, MyCmp_t>(e2.eid, 4);
    gtx.destroyEntityById<Player>(e1.eid);
    return 0;
}
