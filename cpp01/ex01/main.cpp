#include "Zombie.hpp"
#include <iostream>

void announceAndKillZombies(int N, Zombie* zombies) {
  if (!zombies) {
    return;
  }

  for (int i = 0; i < N; i++) {
    zombies[i].announce();
  }
  delete[] zombies;
}

int main() {
  const int zombies_amount = 10;
  Zombie* zombies = zombieHorde(zombies_amount, "Abobus");
  announceAndKillZombies(zombies_amount, zombies);
  return 0;
} 