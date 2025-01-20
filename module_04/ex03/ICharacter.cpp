/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 16:48:39 by jsobreir          #+#    #+#             */
/*   Updated: 2025/01/20 19:45:11 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"


Character::Character(): _totalUnequiped(0) {
	
}

Character::Character(std::string name) {
	_name = name;
	_totalUnequiped = 0;
}

Character::Character(const Character &character) {
	this->_name = character.getName();
	_totalUnequiped = 0;
	for (int i = 0; i < 4; i++) {
		if (character.slot[i])
			this->slot[i] = character.slot[i]->clone();
		else
			break ;
	}
}


Character &Character::operator=(Character const &character) {
	_totalUnequiped = 0;
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

Character::~Character() {
	for (int i = 0; i < _totalUnequiped; i++) {
		if (unequiped)
			delete unequiped;
		else
			break ;
		unequiped++;
	}	
}

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
	AMateria *ptr = unequiped;
	for (int i = 0; i < _totalUnequiped; i++)
		ptr++;
	ptr = slot[idx];
	slot[idx] = NULL;
}

void Character::use(int idx, ICharacter &target) {
	if (slot[idx])
	{
		slot[idx]->use(target);
	}
	else
		std::cout << "No Materia in that slot!" << std::endl;
}