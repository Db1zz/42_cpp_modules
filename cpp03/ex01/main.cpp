#include "ScavTrap.hpp"

int main() {
  ScavTrap trap("Abobus");
  trap.attack("Abobus_enemy");
  trap.guardGate();
  return 0;
}