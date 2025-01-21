#include "Zombie.hpp"
#include <string>

extern Zombie* newZombie(std::string name);
extern void randomChump(std::string name);

int main() {
  Zombie* zombik = newZombie("Zombik");
  zombik->announce();
  randomChump("Random");
  delete zombik;
  return 0;
}