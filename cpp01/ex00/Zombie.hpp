#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>

class Zombie {
public:
  Zombie() = default;
  Zombie(std::string name);
  ~Zombie();
  void announce();

private:
  std::string _name;
};

#endif	// ZOMBIE_H