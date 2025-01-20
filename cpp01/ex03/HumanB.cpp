#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>
#include <string>

HumanB::HumanB(const std::string name)
  : _name(name) {}

void HumanB::setWeapon(const Weapon& weapon) {
  _weapon.setType(weapon.getType());
}

void HumanB::attack() {
  std::cout << _name << "attacks with their " << _weapon.getType() << std::endl;
}
