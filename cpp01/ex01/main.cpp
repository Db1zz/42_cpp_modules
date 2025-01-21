#include "Zombie.hpp"
#include <iostream>

void announceZombies(int N, Zombie* zombies) {
  if (!zombies) {
    return;
  }

  for (int i = 0; i < N; i++) {
    zombies[i].announce();
  }
}

int main() {
  const int zombies_amount = 10;
  Zombie* zombies = zombieHorde(zombies_amount, "Abobus");
  announceZombies(zombies_amount, zombies);
  delete[] zombies;
  return 0;
} 