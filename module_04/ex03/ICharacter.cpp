/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 16:48:39 by jsobreir          #+#    #+#             */
/*   Updated: 2025/01/12 19:05:06 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"

ICharacter::~ICharacter() {
	std::cout << "ICharacter was destructed" << std::endl;
}

Character::Character(): _totalUnequiped(0) {
	
}

Character::Character(std::string name) {
	_name = name;
	_totalUnequiped = 0;
	std::cout << "Character was copied" << std::endl;
}

Character::Character(const Character &character) {
	this->_name = character.getName();
	_totalUnequiped = 0;
	for (int i = 0; character.slot[i]; i++) {
		this->slot[i] = character.slot[i]->clone();
	}
}

Character::~Character() {
	
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
	
}

void Character::equip(AMateria *m) {
	for (int i = 0; i < 4; i++) {
		if (!slot[i] && i != 3)
			slot[i] = m;
	}
}

void Character::unequip(int idx) {
	AMateria *ptr = unequiped;
	for (int i; i < _totalUnequiped; i++)
		ptr++;
	ptr = slot[idx];
	slot[idx] = NULL;
}

void Character::use(int idx, ICharacter &target) {
	slot[idx]->use(target);
}
