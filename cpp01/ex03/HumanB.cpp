#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>
#include <string>

HumanB::HumanB(const std::string name)
  : _name(name), _weapon(NULL) {}

void HumanB::setWeapon(Weapon& weapon) {
  _weapon = &weapon;
}

void HumanB::attack() {
  if (!_weapon) {
    std::cout << _name << " cannot attack without weapon\n";
    return;
  }
  std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}
