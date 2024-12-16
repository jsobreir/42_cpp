/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal copy 2.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:22:17 by jsobreir          #+#    #+#             */
/*   Updated: 2024/12/16 19:50:03 by jsobreir         ###   ########.fr       */
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
	if (_type == "Dog")
		std::cout << "au au au" << std::endl;
	else
		std::cout << "miau miau" << std::endl;
}

std::string WrongAnimal::getType(void) const {
	return _type;
}
