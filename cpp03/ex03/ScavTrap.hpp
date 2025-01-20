#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class ScavTrap : virtual public ClapTrap {
public:
  ScavTrap();
  ScavTrap(const std::string& _name);
  ~ScavTrap();
  void guardGate();
};

#endif  // SCAV_TRAP_HPP