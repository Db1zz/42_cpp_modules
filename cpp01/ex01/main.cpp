#include "Zombie.hpp"
#include <iostream>

void	announceAndKillZombies(int N, Zombie* zombies) {
	if (!zombies) {
		return;
	}

	for (int i = 0; i < N; i++) {
		Zombie* curr_zombie = zombies + (i * sizeof(Zombie*));
		curr_zombie->announce();
		delete curr_zombie;
	}
}

int main() {
	const int zombies_amount = 10;
	Zombie* zombies = zombieHorde(zombies_amount, "Abobus");
	announceAndKillZombies(zombies_amount, zombies);
	return 0;
}