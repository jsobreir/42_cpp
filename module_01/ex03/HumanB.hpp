#ifndef HUMAN_B_H
# define HUMAN_B_H

# include <iostream>
# include "Weapon.hpp"

class	HumanB {
	public:
		HumanB (std::string _name);
		~HumanB() { };
		void	setWeapon( Weapon &weapon ) { _weapon = &weapon; }
		void	attack( void );
	private:
		std::string	name;
		Weapon *_weapon;
} ;

#endif
