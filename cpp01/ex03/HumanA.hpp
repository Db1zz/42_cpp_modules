#ifndef HUMANA_H
#define HUMANA_H

#include "Weapon.hpp"
#include <string>

class HumanA {
public:
  HumanA(const std::string& name, const Weapon &weapon);
  void attack();
private:
  std::string _name;
  Weapon _weapon;
};

#endif  // HUMANA_H