#ifndef HUMAN_A_H
# define HUMAN_A_H

# include <iostream>
# include "Weapon.hpp"

class	HumanA {
	public:
		HumanA(std::string _name, Weapon& initial_weapon);
		~HumanA() { };
		void	attack(void);
	private:
		std::string	name;
		Weapon&	weapon;
} ;

#endif