/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:36:37 by jsobreir          #+#    #+#             */
/*   Updated: 2025/01/20 18:57:38 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() { }

AMateria::AMateria(std::string const & type): _type(type) { }

AMateria::AMateria(const AMateria &amateria) {
	*this = amateria;
}

AMateria &AMateria::operator=(AMateria const &amateria) {
	if (this != &amateria) {
		_type = amateria._type;
	}
	return (*this);
}

AMateria::~AMateria() { }

std::string const & AMateria::getType() const {
	return _type;
}

void AMateria::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
