#include "HumanB.hpp"

HumanB::HumanB (std::string _name) : name(_name), _weapon(NULL) {}

void	HumanB::attack() {
	if (!this->_weapon)
		std::cout << name << " doesn't have a weapon!" << std::endl;
	else
		std::cout << name << " attacks with their " << _weapon->getType() << std::endl; 
}