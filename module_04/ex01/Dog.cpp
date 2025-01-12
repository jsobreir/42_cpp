/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:19:05 by jsobreir          #+#    #+#             */
/*   Updated: 2025/01/09 12:02:57 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal(), _type("Dog"){
	_brain = new Brain;
	std::cout << "Dog with brain created!" << std::endl;
}

Dog::Dog(const Dog &dog) : Animal() , _brain(new Brain(*dog._brain)) {
	_type = dog._type;
}

Dog Dog::operator=(Dog const &dog) {
	if (this != &dog) {
		_type = dog._type;
		if (_brain)
			delete _brain;
		_brain = new Brain;
		*this->_brain = *dog._brain;
	}
	return *this;
}

Dog::~Dog() {
	delete _brain;
	std::cout << "Dog with brain destroyed!" << std::endl;
}

void Dog::makeSound(void) const {
	std::cout << "au au au" << std::endl;
}

std::string Dog::getType(void) const {
	return _type;
}

void Dog::setIdea( int i, std::string idea ) {
	this->_brain->setIdea(i, idea);
}

const std::string Dog::getIdea( int i ) {
	return this->_brain->getIdea(i);
}
