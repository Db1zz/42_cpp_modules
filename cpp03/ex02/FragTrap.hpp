#ifndef FRAG_TRAP_HPP
#define FRAG_TRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class FragTrap : public ClapTrap {
public:
  FragTrap(const std::string& _name);
  ~FragTrap();
  void highFivesGuys();
};

#endif  // FRAG_TRAP_HPP