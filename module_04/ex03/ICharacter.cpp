/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 16:48:39 by jsobreir          #+#    #+#             */
/*   Updated: 2025/01/21 12:38:10 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"


Character::Character() {
	int idx = -1;
	while (++idx < 4) {
		this->slot[idx] = NULL;
	}
}

Character::Character(std::string name) {
	_name = name;
	int idx = -1;
	while (++idx < 4) {
		this->slot[idx] = NULL;
	}
}

Character::Character(const Character &character) {
	this->_name = character.getName();
	for (int i = 0; i < 4; i++) {
		if (character.slot[i])
			this->slot[i] = character.slot[i]->clone();
		else
			break ;
	}
}


Character &Character::operator=(Character const &character) {
	_name = character.getName();
	for (int i = 0; i < 4; i++) {
		delete slot[i];
		slot[i] = NULL;
	}
	for (int i = 0; i < 4; i++) {
		this->slot[i] = character.slot[i]->clone();
	}
	return *this;
}
ICharacter::~ICharacter() {}

Character::~Character() {}

std::string const & Character::getName() const {
	return (_name);
}

void Character::equip(AMateria *m) {
	for (int i = 0; i < 4; i++) {
		if (!slot[i]) {
			slot[i] = m;
			break ;
		}
	}
}

void Character::unequip(int idx) {
	if (slot[idx])
		slot[idx] = NULL;
	else
		std::cout << "Inventory is already empty!" << std::endl;
}

void Character::use(int idx, ICharacter &target) {
	if (slot[idx])
	{
		slot[idx]->use(target);
	}
	else
		std::cout << "No Materia in that slot!" << std::endl;
}
