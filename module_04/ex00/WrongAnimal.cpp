/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:22:17 by jsobreir          #+#    #+#             */
/*   Updated: 2024/12/17 10:05:40 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
}

WrongAnimal::WrongAnimal(std::string type) : _type(type) {	
}

WrongAnimal::WrongAnimal(const WrongAnimal &wrongAnimal) {
	*this = wrongAnimal;
}

WrongAnimal WrongAnimal::operator=(WrongAnimal const &wrongAnimal) {
	if (this != &wrongAnimal) {
		_type = wrongAnimal._type;
	}
	return *this;
}

WrongAnimal::~WrongAnimal() {
}

void WrongAnimal::makeSound(void) const {
	std::cout << "This is the wrong animal class and it doesn't make any sound!" << std::endl;
}

std::string WrongAnimal::getType(void) const {
	return _type;
}
