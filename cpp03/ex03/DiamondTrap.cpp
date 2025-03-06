#include "DiamondTrap.hpp"
#include <string>
#include <iostream>

DiamondTrap::DiamondTrap(const std::string& name)
  : ClapTrap(name + "_clap_name"), _name(name)
{
  std::cout << "DiamondTrap constructor called\n";
  _hit_points = FragTrap::_hit_points;
  _energy_points = ScavTrap::_energy_points;
  _attack_damage = FragTrap::_attack_damage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &to_copy)
  : ClapTrap(to_copy), ScavTrap(to_copy), FragTrap(to_copy), _name(to_copy._name)
{
  std::cout << "DiamondTrap copy Constructor called\n";
  *this = to_copy;
}

DiamondTrap::~DiamondTrap()
{
  std::cout << "DiamondTrap destructor called\n";
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &to_copy) {
  std::cout << "DiamondTrap copy Constructor called\n";
  ClapTrap::operator=(to_copy);
  _name = to_copy._name;
  return *this;
}

void DiamondTrap::attack(const std::string& target) {
  this->ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
  if (_hit_points <= 0) {
    std::cout << " is dead and cannot take any actions\n";
  }
  std::cout << this->ClapTrap::_name << '\n'
            << this->DiamondTrap::_name << '\n';
}