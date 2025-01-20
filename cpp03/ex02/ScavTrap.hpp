#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class ScavTrap : public ClapTrap {
public:
  ScavTrap(const std::string& _name);
  ~ScavTrap();
  void guardGate();
};

#endif  // SCAV_TRAP_HPP