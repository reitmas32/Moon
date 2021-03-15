#include "../../../template/core/cmp/cmp.tpp"

namespace Moon::Core
{
    ComponentSingleton_t::ComponentSingleton_t() {}

    ComponentSingleton_t::~ComponentSingleton_t() {}

    Moon::Alias::ComponentType ComponentSingleton_t::getComponentType() noexcept
    {
        static Moon::Alias::ComponentType type = ++nextType;
        return type;
    }
} // namespace Moon::Core
