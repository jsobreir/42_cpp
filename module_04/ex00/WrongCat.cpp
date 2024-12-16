/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:22:17 by jsobreir          #+#    #+#             */
/*   Updated: 2024/12/16 19:50:22 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("Cat"), _type("Cat") {
}

WrongCat::WrongCat(const WrongCat &wrongCat) {
	*this = wrongCat;
}

WrongCat WrongCat::operator=(WrongCat const &wrongCat) {
	if (this != &wrongCat) {
		_type = wrongCat._type;
	}
	return *this;
}

WrongCat::~WrongCat() {
}

// void WrongCat::makeSound(void) const {
// 	std::cout << "miau miau" << std::endl;
// }

std::string WrongCat::getType(void) const {
	return _type;
}