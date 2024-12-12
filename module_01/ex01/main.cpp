#include "Zombie.hpp"

int main (void) {
	Zombie *zombies;
	int N = 10;

	zombies = zombieHorde(N, "Joao");

	for (int i = 0; i < N; i++)
	{
		zombies[i].announce();
	}
	delete[] zombies;
}
