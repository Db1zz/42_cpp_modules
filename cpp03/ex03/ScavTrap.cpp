#include "ScavTrap.hpp"
#include <string>
#include <iostream>

ScavTrap::ScavTrap() {
  std::cout << "ScavTrap default constructor called\n";
}

ScavTrap::ScavTrap(const std::string& _name)
  : ClapTrap(_name)
{
  std::cout << "ScavTrap constructor called\n";
  _hit_points = 100;
  _energy_points = 50;
  _attack_damage = 20;
}

ScavTrap::~ScavTrap() {
  std::cout << "ScavTrap destructor called\n";
}

void ScavTrap::guardGate() {
  std::cout << _name << " is now in the Gate keeper mode\n";
}