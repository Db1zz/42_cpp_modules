#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie()
  : _name("Unknown Zombie")
{
  std::cout << "Zombie Default Constructor was called!\n";
}

Zombie::Zombie(std::string name)
  : _name(name)
{
  std::cout << "Zombie Constructor was called!\n";
}

Zombie::~Zombie() {
  std::cout << "Destroyed: " << _name << std::endl;
}

void Zombie::announce() {
  std::cout << _name << ": BraiiiiiiinnnzzzZ...\n";
}
