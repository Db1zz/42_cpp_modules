#include "DiamondTrap.hpp"
#include <string>
#include <iostream>

DiamondTrap::DiamondTrap(const std::string& name)
  : ClapTrap(name + "_clap_name"), _name(name)
{
  std::cout << "DiamondTrap constructor called\n";
  _hit_points = 100;
  _energy_points = 50;
  _attack_damage = 30;
}

DiamondTrap::~DiamondTrap()
{
  std::cout << "DiamondTrap destructor called\n";
}

void DiamondTrap::whoAmI() {
  std::cout << this->ClapTrap::_name << '\n'
            << this->DiamondTrap::_name << '\n';
}