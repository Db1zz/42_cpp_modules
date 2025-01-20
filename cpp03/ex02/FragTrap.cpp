#include "FragTrap.hpp"
#include <string>
#include <iostream>

FragTrap::FragTrap(const std::string& _name)
  : ClapTrap(_name)
{
  std::cout << "FragTrap constructor called\n";
  _hit_points = 100;
  _energy_points = 100;
  _attack_damage = 30;
}

FragTrap::~FragTrap() {
  std::cout << "FragTrap destructor called\n";
}

void FragTrap::highFivesGuys() {
  std::cout << "SPECIAL FEATURE.................\n";
}