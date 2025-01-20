#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() {}

Zombie::Zombie(std::string name)
  : _name(name) {}

Zombie::~Zombie() {
  std::cout << "Destroyed: " << _name << std::endl;
}

void Zombie::announce() {
  std::cout << _name << ": BraiiiiiiinnnzzzZ...\n";
}
