/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:22:17 by jsobreir          #+#    #+#             */
/*   Updated: 2024/12/18 11:15:57 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Brain.hpp"

AAnimal::AAnimal() {
	std::cout << "AAnimal created!" << std::endl;
}

AAnimal::AAnimal(std::string type) : _type(type) {
	std::cout << "AAnimal of type " << _type << " created!" << std::endl;
}

AAnimal::AAnimal(const AAnimal &aanimal) {
	*this = aanimal;
}

AAnimal &AAnimal::operator=(AAnimal const &aanimal) {
	if (this != &aanimal) {
		_type = aanimal._type;
	}
	return *this;
}

AAnimal::~AAnimal() {
	std::cout << "Animal destroyed!" << std::endl;
}

void AAnimal::makeSound(void) const {
	std::cout << "This is the aanimal class and it doesn't make any sound!" << std::endl;
}

std::string AAnimal::getType(void) const {
	return _type;
}
