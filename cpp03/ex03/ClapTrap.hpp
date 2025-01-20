#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP

#include <string>

class ClapTrap {
public:
  ClapTrap(const std::string& name);
  ClapTrap();
  ~ClapTrap();
  void attack(const std::string& target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
protected:
  std::string _name;
  int _hit_points;
  int _energy_points;
  int _attack_damage;
};

#endif  // CLAP_TRAP_HPP