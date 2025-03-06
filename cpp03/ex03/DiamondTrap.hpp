#ifndef DIAMOND_TRAP_HPP
#define DIAMOND_TRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <string>

class DiamondTrap : public ScavTrap, public FragTrap {
public:
  DiamondTrap(const std::string& name = "DefaultName");
  DiamondTrap(const DiamondTrap &to_copy);
  ~DiamondTrap();
  DiamondTrap &operator=(const DiamondTrap &to_copy);

  void attack(const std::string& target);
  void whoAmI();
private:
  std::string _name;
};

#endif  // DIAMOND_TRAP_HPP