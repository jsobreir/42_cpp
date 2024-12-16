/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:19:08 by jsobreir          #+#    #+#             */
/*   Updated: 2024/12/16 19:44:26 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat"), _type("Cat") {
}

Cat::Cat(const Cat &cat) {
	*this = cat;
}

Cat Cat::operator=(Cat const &cat) {
	if (this != &cat) {
		_type = cat._type;
	}
	return *this;
}

Cat::~Cat() {
}

// void Cat::makeSound(void) const {
// 	std::cout << "miau miau" << std::endl;
// }

std::string Cat::getType(void) const {
	return _type;
}