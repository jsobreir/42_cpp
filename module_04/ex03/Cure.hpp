/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:26:57 by jsobreir          #+#    #+#             */
/*   Updated: 2025/01/11 16:35:39 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AMateria.hpp"

class Cure: public AMateria
{
	protected:
		std::string	_type;
	
	public:
		Cure();
		Cure(std::string const & type);
		Cure(const Cure &cure);
		Cure &operator=(Cure const &cure);
		std::string const & getType() const; //Returns the Cure type
		Cure* clone() const;
		void use(ICharacter& target);
};