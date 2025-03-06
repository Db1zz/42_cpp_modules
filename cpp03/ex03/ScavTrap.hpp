#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class ScavTrap : virtual public ClapTrap {
public:
  ScavTrap(const std::string& name = "DefaultName");
  ScavTrap(const ScavTrap &to_copy);
  ~ScavTrap();
  ScavTrap &operator=(const ScavTrap &to_copy);

  void attack(const std::string& target);
  void guardGate();
};

#endif  // SCAV_TRAP_HPP