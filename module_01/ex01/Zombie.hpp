#ifndef ZOMBIE_HORDE_H
# define ZOMBIE_HORDE_H

# include <iostream>

class Zombie {
	public:
		Zombie () {};
		Zombie ( std::string name );
		~Zombie (void);
		void		setName(std::string	_name);
		void	announce ( void );

	private:
		std::string	_name;
} ;

Zombie* zombieHorde( int N, std::string name );

#endif