//  src/main.cpp

#include <iostream>

//Info Platform
#include <Moon/include/tools/platform_info.hpp>

//Component
#include <Moon/template/core/cmp/cmp.tpp>

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

int main(int argc, char const *argv[])
{
    MyCmp_t cmp = MyCmp_t(0, 45); // eid = 0, data = 45
    std::cout << "MyCmp_t eid: "<<cmp.eid<<", data: " << cmp.data << std::endl;
    return 0;
}
