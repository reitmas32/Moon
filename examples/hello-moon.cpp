#include "../template/cmp/cmp.tpp"
#include <iostream>

struct Sprite_t : Moon::Core::Component_t<Sprite_t> {
  /* data */
};

int main() {
  Sprite_t s = Sprite_t();
  std::cout << Sprite_t::getComponentType() << '\n';
  return 0;
}