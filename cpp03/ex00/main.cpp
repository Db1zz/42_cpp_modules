#include "ClapTrap.hpp"

int main() {
  ClapTrap trap("Abobus");
  trap.attack("Abobus_enemy");
  trap.takeDamage(1);
  trap.beRepaired(10);
  trap.beRepaired(1);
  trap.takeDamage(19);
  trap.beRepaired(1);
  trap.takeDamage(19);
  trap.attack("Abobus_enemy");
  return 0;
}