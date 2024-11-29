#include "HumanA.hpp"

HumanA::HumanA(std::string _name, Weapon &initial_weapon) : name(_name), weapon(initial_weapon) {}

void	HumanA::attack() {
	std::cout << name << " attacks with their " << weapon.getType() << std::endl; 
}