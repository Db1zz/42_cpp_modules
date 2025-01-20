#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(const std::string& name, const Weapon &weapon)
  : _name(name), _weapon(weapon.getType()) {}

void HumanA::attack() {
  std::cout << _name << "attacks with their " << _weapon.getType() << std::endl;
}
