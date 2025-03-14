/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:30:49 by jsobreir          #+#    #+#             */
/*   Updated: 2024/12/16 18:03:48 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>

class Fixed {
	private:
		int	_integer;
		static const int _f_bits = 8;
	public:
		Fixed();
		Fixed(const Fixed &fixed);
		Fixed& operator=(const Fixed &fixed);
		~Fixed();
		int getRawBits( void ) const;
		void setRawBits( int const raw );
} ;
