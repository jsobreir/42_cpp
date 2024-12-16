/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:31:55 by jsobreir          #+#    #+#             */
/*   Updated: 2024/12/16 17:07:52 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _raw(0) { }

Fixed::Fixed(const int integer) {
	_raw = integer << _f_bits;
}

Fixed::Fixed(const float value) {
	_raw = roundf(value * (1 << _f_bits));
}

Fixed::Fixed(const Fixed &fixed) {
	*this = fixed;
}

Fixed& Fixed::operator=(const Fixed &fixed) {
	if (this != &fixed)
		setRawBits(fixed.getRawBits());
	return *this;
}

Fixed::~Fixed() { }

int Fixed::getRawBits( void ) const {
	return _raw;
}

void Fixed::setRawBits( int const raw ) {
	_raw = raw;
}

float Fixed::toFloat( void ) const {
	return (float)_raw / (1 << _f_bits);
}

int Fixed::toInt( void ) const {
	return	_raw >> _f_bits;
}

std::ostream& operator<<(std::ostream& os, const Fixed &fixed) {
	os << fixed.toFloat();
	return os;
}

bool Fixed::operator<(const Fixed &fixed) {
	return _raw < fixed._raw;
}

bool Fixed::operator>(const Fixed &fixed) {
	return _raw > fixed._raw;
}

bool Fixed::operator!=(const Fixed &fixed) {
	return _raw != fixed._raw;
}

bool Fixed::operator==(const Fixed &fixed) {
	return _raw == fixed._raw;
}

bool Fixed::operator>=(const Fixed &fixed) {
	return _raw >= fixed._raw;
}

bool Fixed::operator<=(const Fixed &fixed) {
	return _raw <= fixed._raw;
}

Fixed Fixed::operator+(const Fixed &rhs) const {
	Fixed ret;
	ret.setRawBits(this->getRawBits() + rhs.getRawBits());
	return (ret);
}

Fixed Fixed::operator-(const Fixed &rhs) const {
	Fixed ret;
	ret.setRawBits(this->getRawBits() - rhs.getRawBits());
	return (ret);
}

Fixed Fixed::operator*(const Fixed &rhs) const {
	Fixed ret;
	ret.setRawBits((_raw * rhs.getRawBits()) >> _f_bits);
	return (ret);
}

Fixed Fixed::operator/(const Fixed &rhs) const {
	Fixed ret;
	ret.setRawBits((_raw / rhs.getRawBits()) >> _f_bits);
	return (ret);
}

Fixed& Fixed::operator++(void) {
	_raw ++;
	return *this;
}

Fixed& Fixed::operator--(void) {
	_raw --;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed ret(*this);
	++(*this);
	return ret;
}

Fixed Fixed::operator--(int) {
	Fixed ret(*this);
	--(*this);
	return ret;
}

Fixed& Fixed::max(Fixed &a, Fixed &b) {
	if (a._raw > b._raw)
		return a;
	return b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b) {
	if (a._raw > b._raw)
		return a;
	return b;
}

Fixed& Fixed::min(Fixed &a, Fixed &b) {
	if (a._raw > b._raw)
		return b;
	return a;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b) {
	if (a._raw > b._raw)
		return b;
	return a;
}
