/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:27:01 by jsobreir          #+#    #+#             */
/*   Updated: 2025/01/11 19:03:44 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AMateria.hpp"

class Ice: public AMateria
{
	protected:
		std::string _type;
	
	public:
		Ice();
		Ice(std::string const & type);
		Ice(const Ice &ice);
		Ice &operator=(Ice const &ice);
		std::string const & getType() const; //Returns the materia type
		Ice* clone() const;
		void use(ICharacter& target);
};