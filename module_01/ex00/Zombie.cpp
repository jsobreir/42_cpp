#include "Zombie.hpp"

Zombie::Zombie (std::string name) {
	_name = name;
	std::cout << "Zombie " << name << " was created!" << std::endl;
}

Zombie::~Zombie () {
	std::cout << "Zombie " << _name << " was destroyed!" << std::endl;
}

void	Zombie::announce ( void ) {
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

