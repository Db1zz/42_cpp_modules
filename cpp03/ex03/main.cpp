#include "DiamondTrap.hpp"

int main() {
  DiamondTrap trap("Abobus");
  trap.whoAmI();
  trap.attack("Abobus_enemy");

  {
    DiamondTrap a(trap);
    a.attack("asd");
  }
  return 0;
}
