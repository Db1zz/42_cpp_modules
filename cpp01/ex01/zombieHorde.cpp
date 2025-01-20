#include "Zombie.hpp"
#include <iostream>

Zombie* zombieHorde(int N, std::string name) {
	Zombie* zombies = new Zombie[N];
	if (zombies == 0) {
		std::cout << "Error! Zombie allocation failed\n";
		return NULL;
	}

	for (int i = 0; i < N; i++) {
		Zombie* curr_zombie = zombies + (i * sizeof(Zombie*));
		curr_zombie->setName(name);
	}
	return (zombies);
}