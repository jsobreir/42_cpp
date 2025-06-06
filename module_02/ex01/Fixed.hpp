/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:31:14 by jsobreir          #+#    #+#             */
/*   Updated: 2024/12/16 15:53:18 by jsobreir         ###   ########.fr       */
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
} ;

std::ostream& operator<<(std::ostream& os, const Fixed &fixed);
