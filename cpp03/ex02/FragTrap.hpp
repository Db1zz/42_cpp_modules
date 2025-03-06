#ifndef FRAG_TRAP_HPP
#define FRAG_TRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class FragTrap : public ClapTrap {
public:
  FragTrap(const std::string& name = "DefaultName");
  FragTrap(const FragTrap &to_copy);
  ~FragTrap();
  FragTrap &operator=(const FragTrap &to_copy);
  void highFivesGuys();
};

#endif  // FRAG_TRAP_HPP