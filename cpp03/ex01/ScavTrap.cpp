#include "ScavTrap.hpp"
#include <string>
#include <iostream>

ScavTrap::ScavTrap(const std::string& _name)
  : ClapTrap(_name)
{
  std::cout << "ScavTrap Constructor called\n";
  _hit_points = 100;
  _energy_points = 50;
  _attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &to_copy) 
  : ClapTrap(to_copy)
{
  std::cout << "ScavTrap copy Constructor called\n";
}

ScavTrap::~ScavTrap() {
  std::cout << "ScavTrap Destructor called\n";
}

ScavTrap &ScavTrap::operator=(const ScavTrap &to_copy) {
  std::cout << "ScavTrap copy Constructor called\n";
  ClapTrap::operator=(to_copy);
  return *this;
}

void ScavTrap::guardGate() {
  if (_hit_points <= 0) {
    std::cout << _name << " is dead and cannot take any actions\n";
    return;
  }
  std::cout << _name << " is now in the Gate keeper mode\n";
}