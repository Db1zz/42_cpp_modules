#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() {}

Zombie::~Zombie() {
  std::cout << "Destroyed: " << _name << std::endl;
}

void Zombie::announce() {
  std::cout << _name << ": BraiiiiiiinnnzzzZ...\n";
}

void Zombie::setName(std::string name) {
  _name = name;
}
