/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 16:28:52 by jsobreir          #+#    #+#             */
/*   Updated: 2025/01/20 18:30:37 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(): AMateria("ice") { }

Ice::Ice(const Ice &ice): AMateria("ice")  {
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