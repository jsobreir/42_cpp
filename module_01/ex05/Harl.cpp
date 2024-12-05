#include "Harl.hpp"

void Harl::debug (void){
	std::cout << "This is a debugging message!" << std::endl;
}

void Harl::info (void){
	std::cout << "This is an info message!" << std::endl;
}

void Harl::warning (void){
	std::cout << "This is a warning message!" << std::endl;
}

void Harl::error (void){
	std::cout << "This is an error message!" << std::endl;
}

void Harl::complain( std::string level ) {
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void	(Harl::*ptrToMemberFunc[4]) ( void ) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (int i = 0; i < 4; i++) {
		if (level == levels[i])
		{
			(this->*ptrToMemberFunc[i]) ();
			return ;
		}
	}
}
