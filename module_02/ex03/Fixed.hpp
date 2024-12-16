/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:32:10 by jsobreir          #+#    #+#             */
/*   Updated: 2024/12/16 17:09:34 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <cmath>

class Fixed {
	private:
		int	_raw;
		static const int _f_bits = 8;
	public:
		Fixed();
		Fixed(const int integer);
		Fixed(const float value);
		Fixed(const Fixed &fixed);
		Fixed& operator=(const Fixed &fixed);
		~Fixed();
		float toFloat( void ) const;
		int toInt( void ) const;
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		bool operator<(const Fixed &fixed);
		bool operator>(const Fixed &fixed);
		bool operator!=(const Fixed &fixed);
		bool operator==(const Fixed &fixed);
		bool operator>=(const Fixed &fixed);
		bool operator<=(const Fixed &fixed);
		Fixed operator+(const Fixed &rhs) const;
		Fixed operator-(const Fixed &rhs) const;
		Fixed operator*(const Fixed &rhs) const;
		Fixed operator/(const Fixed &rhs) const;
		Fixed& operator++(void); // Pre Increment
		Fixed& operator--(void); // Pre Decrement
		Fixed operator++(int); // Post Increment
		Fixed operator--(int); // Post Decrement
		static Fixed& max(Fixed &a, Fixed &b);
		static const Fixed& max(const Fixed &a, const Fixed &b);
		static Fixed& min(Fixed &a, Fixed &b);
		static const Fixed& min(const Fixed &a, const Fixed &b);


} ;

std::ostream& operator<<(std::ostream& os, const Fixed &fixed);
