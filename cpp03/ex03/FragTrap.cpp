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

FragTrap::FragTrap(const FragTrap &to_copy) 
  : ClapTrap(to_copy)
{
  std::cout << "FragTrap copy Constructor called\n";
}

FragTrap::~FragTrap() {
  std::cout << "FragTrap destructor called\n";
}

FragTrap &FragTrap::operator=(const FragTrap &to_copy) {
  std::cout << "FragTrap copy Constructor called\n";
  ClapTrap::operator=(to_copy);
  return *this;
}

void FragTrap::highFivesGuys() {
  if (_hit_points <= 0) {
    std::cout << _name << " is dead and cannot take any actions\n";
    return;
  }
  std::cout << "SPECIAL FEATURE.................\n";
}