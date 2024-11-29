#include "Zombie.hpp"

int main (void)
{
	Zombie *zombie;

	zombie = newZombie("Joao");
	zombie->announce();
	randomChump("Miguel");
	delete zombie;
	return (0);
}