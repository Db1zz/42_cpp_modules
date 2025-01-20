#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(const std::string& name)
  : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
  std::cout << "ClapTrap Constructor called\n";
}

ClapTrap::ClapTrap()
{
  std::cout << "ClapTrap default Constructor called\n";
}

ClapTrap::~ClapTrap() {
  std::cout << "ClapTrap destructor called\n";
}

void ClapTrap::attack(const std::string& target) {
  std::cout << _name << " attacks " << target
            << ", causing " << _attack_damage << " points of damage!\n";
  
}

void ClapTrap::takeDamage(unsigned int amount) {
  _hit_points -= amount;
  if (_hit_points <= 0) {
    std::cout << _name << " is dead\n";
  }
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (_energy_points == 0) {
    std::cout << _name << " not enought energy to repair!\n";
    return ;
  }
  --_energy_points;
  _hit_points += amount;
  std::cout << _name << " got repaired and now has " << _hit_points << " hp\n";
}