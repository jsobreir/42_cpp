/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:36:44 by jsobreir          #+#    #+#             */
/*   Updated: 2025/01/20 19:57:18 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource() { }

MateriaSource::MateriaSource(const MateriaSource &other) {
	*this = other;
}

MateriaSource &MateriaSource::operator=(MateriaSource const &other) {
	if (this != &other) {
		for (int i = 0; i < 4; i++) {
			memory[i] = other.memory[i];
		}
	}
	return *this;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++) {
		if (memory[i])
			delete memory[i];
		else
			break ;
	}
}

void MateriaSource::learnMateria(AMateria *materia) {
	std::string type = materia->getType();
	for (int i = 0; i < 4; i++) {
		if (memory[i] && type == memory[i]->getType())
		{
			std::cout << "Already exists in memory." << std::endl;
			break ;
		}
		else if (!memory[i])
		{
			memory[i] = materia->clone();
			break ;
		}
	}
}

AMateria *MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++) {
		if (!memory[i])
		{
			break ;
		}
		else if (type == memory[i]->getType())
		{
			return memory[i]->clone();
		}
	}
	return 0;
}
