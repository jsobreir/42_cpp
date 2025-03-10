/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:22:17 by jsobreir          #+#    #+#             */
/*   Updated: 2024/12/17 10:22:40 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {
}

Animal::Animal(std::string type) : _type(type) {	
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
}

void Animal::makeSound(void) const {
	std::cout << "This is the animal class and it doesn't make any sound!" << std::endl;
}

std::string Animal::getType(void) const {
	return _type;
}
