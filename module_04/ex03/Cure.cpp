/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:51:46 by jsobreir          #+#    #+#             */
/*   Updated: 2025/01/12 17:52:24 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() {
	std::cout << "Cure was created" << std::endl;
}

Cure::Cure(std::string const & type): _type(type) {
	std::cout << "Cure type constructor called" << std::endl;
}

Cure::Cure(const Cure &cure) {
	*this = cure;
}

Cure &Cure::operator=(Cure const &cure) {
	if (this != &cure) {
		_type = cure._type;
	}
	return *this;
}

std::string const & Cure::getType() const {
	return (_type);
}

Cure* Cure::clone() const {
	return (new Cure);
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
