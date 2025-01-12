/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:22:17 by jsobreir          #+#    #+#             */
/*   Updated: 2024/12/17 13:26:01 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Brain.hpp"

Animal::Animal() {
	std::cout << "Animal created!" << std::endl;
}

Animal::Animal(std::string type) : _type(type) {
	std::cout << "Animal of type " << _type << " created!" << std::endl;
}

Animal::Animal(const Animal &animal) {
	*this = animal;
}

Animal Animal::operator=(Animal const &animal) {
	if (this != &animal) {
		_type = animal._type;
	}
	return *this;
}

Animal::~Animal() {
	std::cout << "Animal destroyed!" << std::endl;
}

void Animal::makeSound(void) const {
	std::cout << "This is the animal class and it doesn't make any sound!" << std::endl;
}

std::string Animal::getType(void) const {
	return _type;
}
