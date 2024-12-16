/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:30:44 by jsobreir          #+#    #+#             */
/*   Updated: 2024/12/16 15:34:30 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default Constructor called" << std::endl;
	_integer = 0;	
}

Fixed::Fixed(const Fixed &fixed) {
	std::cout << "Copy Constructor called" << std::endl;
	*this = fixed;	
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &fixed) {
	std::cout << "Copy Assignment Operator called" << std::endl;
	if (this != &fixed)
		setRawBits(fixed.getRawBits());
	return *this;
}

int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return _integer;
}

void Fixed::setRawBits( int const raw ) {
	_integer = raw;
}
