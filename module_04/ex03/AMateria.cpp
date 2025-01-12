/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:36:37 by jsobreir          #+#    #+#             */
/*   Updated: 2025/01/11 16:43:54 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() {
	std::cout << "AMateria was created" << std::endl;
}

AMateria::AMateria(std::string const & type): _type(type) {
	std::cout << "AMateria was created" << std::endl;
	
}

AMateria::AMateria(const AMateria &amateria) {
	*this = amateria;
}

AMateria &AMateria::operator=(AMateria const &amateria) {
	if (this != &amateria) {
		_type = amateria._type;
	}
	return (*this);
}

std::string const & AMateria::getType() const {
	return _type;
}

// AMateria* AMateria::clone() const {
// 	AMateria *ret;
	
// 	ret = new AMateria;
// }

void AMateria::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at *" << target.getName() << " " << std::endl;
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
