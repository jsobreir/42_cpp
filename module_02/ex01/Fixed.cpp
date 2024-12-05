#include "Fixed.hpp"

// Function does not modify any member variables of the class
int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	// std::cout << _integer;
	return _integer;
}

void Fixed::setRawBits( int const raw ) {
	// std::cout << "setRawBits member function called" << std::endl;
	_integer = raw;
}