/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 16:28:52 by jsobreir          #+#    #+#             */
/*   Updated: 2025/01/21 11:39:08 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(): AMateria::AMateria("ice"), _type() {
	this->_type = AMateria::_type;
}

Ice::Ice(const Ice &ice): AMateria::AMateria(ice)  {
	*this = ice;
}

Ice &Ice::operator=(Ice const &ice) {
	if (this != &ice) {
		_type = ice._type;
	}
	return *this;
}

std::string const & Ice::getType() const {
	return (_type);
}

Ice* Ice::clone() const {
	return (new Ice);
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}