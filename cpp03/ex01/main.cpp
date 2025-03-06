#include "ScavTrap.hpp"

int main() {
  ScavTrap trap("Abobus");
  trap.attack("Abobus_enemy");
  trap.guardGate();
  trap.beRepaired(49);
  trap.attack("Abobus_enemy");
  trap.beRepaired(1);
  trap.takeDamage(149);
  trap.guardGate();

  {
    ScavTrap test_one;
    ScavTrap aboba("TEST");
    aboba.attack("Test1");
    aboba = test_one;
    aboba.attack("Test2");
  }

  return 0;
}