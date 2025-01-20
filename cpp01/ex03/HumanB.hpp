#ifndef HUMANB_H
#define HUMANB_H

#include "Weapon.hpp"
#include <string>

class HumanB {
public:
  HumanB(const std::string name);
  void setWeapon(const Weapon& weapon);
  void attack();
private:
  std::string _name;
  Weapon _weapon;
};

#endif  // HUMANB_H