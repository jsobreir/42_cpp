/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:51:46 by jsobreir          #+#    #+#             */
/*   Updated: 2025/01/21 11:38:56 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(): AMateria::AMateria("cure"){
	this->_type = AMateria::_type;
}

Cure::Cure(const Cure &cure): AMateria::AMateria(cure) {
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
