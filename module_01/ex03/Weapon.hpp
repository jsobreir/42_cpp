#ifndef WEAPON_H
# define WEAPON_H

# include <iostream>

class	Weapon {
	public:
	Weapon() {};
	Weapon(std::string weapon_type);
	~Weapon () {};
	// Getter
		const std::string& getType( void ) { return type; }
	// Setter
		void	setType( std::string new_type ) { type = new_type; }
	private:
		std::string	type;
} ;
#endif
