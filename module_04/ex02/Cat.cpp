/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:19:08 by jsobreir          #+#    #+#             */
/*   Updated: 2024/12/17 16:25:27 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : AAnimal(), _type("Cat") {
	_brain = new Brain;
	std::cout << "Cat with brain created!" << std::endl;
}

Cat::Cat(const Cat &cat) : AAnimal(), _brain(new Brain(*cat._brain)) {
	_type = cat._type;
}

Cat Cat::operator=(Cat const &cat) {
	if (this != &cat) {
		_type = cat._type;
		if (_brain) delete _brain;
		_brain = new Brain;
		*this->_brain = *cat._brain;
	}
	return *this;
}

Cat::~Cat() {
	delete _brain;
	std::cout << "Cat with brain destroyed!" << std::endl;
}

void Cat::makeSound(void) const {
	std::cout << "miau miau" << std::endl;
}

std::string Cat::getType(void) const {
	return _type;
}
