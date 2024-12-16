/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:31:46 by jsobreir          #+#    #+#             */
/*   Updated: 2024/12/16 15:53:12 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	const Fixed &c = a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	const Fixed &d = b;
	bool check;
	Fixed res;

	std::cout << "a = " << a << std::endl;
	std::cout << "++a = " << ++a << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "a++ = " << a++ << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "Max between a and b is: " << Fixed::max( a, b ) << std::endl;
	std::cout << "Max between c and d is: " << Fixed::max( c, d ) << std::endl;
	std::cout << "Min between a and b is: " << Fixed::min( c, d ) << std::endl;
	std::cout << "Min between c and d is: " << Fixed::min( c, d ) << std::endl;
	check = a < b;
	std::cout << "Is a smaller than b?: " << check << std::endl;
	check = a <= b;
	std::cout << "Is a smaller or equal to b?: " << check << std::endl;
	check = a > b;
	std::cout << "Is a bigger than b?: " << check << std::endl;
	check = a >= b;
	std::cout << "Is a bigger or equal to b?: " << check << std::endl;
	res = a * b;
	std::cout << a << " times " << b <<  " = " << res << std::endl;
	res = a + b;
	std::cout << a << " plus " << b <<  " = " << res << std::endl;
	res = a - b;
	std::cout << a << " minus " << b <<  " = " << res << std::endl;
	return 0;
}
