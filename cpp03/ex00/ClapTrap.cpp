#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(const std::string& name)
  : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
  std::cout << "ClapTrap Constructor called\n";
}

ClapTrap::ClapTrap(const ClapTrap &to_copy) {
  std::cout << "ClapTrap copy Constructor called\n";
  *this = to_copy;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &to_copy) {
  std::cout << "ClapTrap copy operator called\n";
  if (this != &to_copy) {
    _name = to_copy._name;
    _hit_points = to_copy._hit_points;
    _energy_points = to_copy._energy_points;
    _attack_damage = to_copy._attack_damage;
  }
  return *this;
}

ClapTrap::~ClapTrap() {
  std::cout << "ClapTrap destructor called\n";
}

void ClapTrap::attack(const std::string& target) {
  if (_hit_points <= 0) {
    std::cout << _name << " is dead and cannot take any actions\n";
    return;
  }
  if (_energy_points - 1 < 0) {
    std::cout << _name << " has not enough energy to attack!\n";
    return;
  }
  std::cout << _name << " attacks " << target
            << ", causing " << _attack_damage << " points of damage!\n";
  --_energy_points;
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (_hit_points <= 0) {
    std::cout << _name << " is already dead\n";
    return;
  }
  _hit_points -= amount;
  if (_hit_points <= 0) {
    std::cout << _name << " is dead\n";
  }
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (_hit_points <= 0) {
    std::cout << _name << " is dead and cannot take any actions\n";
    return;
  }
  if (_energy_points - static_cast<int>(amount) < 0) {
    std::cout << _name << " has not enough energy to repair!\n";
    return;
  }
  _energy_points -= amount;
  _hit_points += amount;
  std::cout << _name << " got repaired and now has " << _hit_points << " hp\n";
}