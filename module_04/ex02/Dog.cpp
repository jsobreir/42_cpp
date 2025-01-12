/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:19:05 by jsobreir          #+#    #+#             */
/*   Updated: 2024/12/17 16:25:33 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : AAnimal(), _type("Dog"){
	_brain = new Brain;
	std::cout << "Dog with brain created!" << std::endl;
}

Dog::Dog(const Dog &dog) : AAnimal() , _brain(new Brain(*dog._brain)) {
	_type = dog._type;
}

Dog Dog::operator=(Dog const &dog) {
	if (this != &dog) {
		_type = dog._type;
		if (_brain) delete _brain;
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
