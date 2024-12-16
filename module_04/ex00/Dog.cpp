/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:19:05 by jsobreir          #+#    #+#             */
/*   Updated: 2024/12/16 19:44:44 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog"), _type("Cat"){
}

Dog::Dog(const Dog &dog) {
	*this = dog;
}

Dog Dog::operator=(Dog const &dog) {
	if (this != &dog) {
		_type = dog._type;
	}
	return *this;
}

Dog::~Dog() {
}

// void Dog::makeSound(void) const {
// 	std::cout << "miau miau" << std::endl;
// }

std::string Dog::getType(void) const {
	return _type;
}
