/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:24:33 by jsobreir          #+#    #+#             */
/*   Updated: 2025/01/12 18:34:14 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AMateria.hpp"

class IMateriaSource
{
	public:
		virtual ~IMateriaSource() {}
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};

class MateriaSource : public IMateriaSource
{
	private:
		AMateria *memory[4];
		
	public:
		MateriaSource();
		MateriaSource(const MateriaSource &other);
		MateriaSource &operator=(MateriaSource const &other);
		~MateriaSource();
		virtual void learnMateria(AMateria *materia);
		virtual AMateria *createMateria(std::string const & type);
};



