/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:31:05 by jsobreir          #+#    #+#             */
/*   Updated: 2024/12/16 18:00:47 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int integer) {
	std::cout << "Int constructor called" << std::endl;
	_raw = integer;
	_raw <<= _f_bits;
};

Fixed::Fixed(const float value) {
	std::cout << "Float constructor called" << std::endl;
	_raw = roundf(value * (1 << _f_bits));
};

Fixed::Fixed(const Fixed &fixed) {
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
};

Fixed& Fixed::operator=(const Fixed &fixed) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed) {
		setRawBits(fixed.getRawBits());
	}
	return *this;
} ;

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
};

int Fixed::getRawBits( void ) const {
	return _raw;
}

void Fixed::setRawBits( int const raw ) {
	_raw = raw;
}

float Fixed::toFloat( void ) const {
	float	ret;

	ret = (float)_raw / (1 << _f_bits);
	return	ret;
}

int Fixed::toInt( void ) const {

	return	_raw >> _f_bits;
}

std::ostream& operator<<(std::ostream& os, const Fixed &fixed) {
	os << fixed.toFloat();
	return os;
}
