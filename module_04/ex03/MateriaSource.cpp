/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:36:44 by jsobreir          #+#    #+#             */
/*   Updated: 2025/01/12 18:46:45 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	std::cout << "Materia Source constructor called!" << std::endl;

}

MateriaSource::MateriaSource(const MateriaSource &other) {
	std::cout << "Materia Source copy destructor called!" << std::endl;
	*this = other;
}

MateriaSource &MateriaSource::operator=(MateriaSource const &other) {
	if (this != &other) {
		for (int i = 0; i < 4; i++) {
			memory[i] = other.memory[i];
		}
	}
}

MateriaSource::~MateriaSource() {
	std::cout << "Materia Source destructor called!" << std::endl;
}

void MateriaSource::learnMateria(AMateria *materia) {
	std::string type = materia->getType();
	for (int i = 0; i < 4; i++) {
		if (type == memory[i]->getType())
			break ;
		if (!memory[i])
			memory[i] = materia;
	}
}

AMateria *MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++) {
		if (type == memory[i]->getType())
			return memory[i]->clone();
	}
}
