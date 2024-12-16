/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:28:46 by jsobreir          #+#    #+#             */
/*   Updated: 2024/12/16 15:28:47 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name) : _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	_name = name;
	std::cout << "ClapTrap " << _name << " was created." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap) {
	*this = clapTrap;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& clapTrap) {
	if (this != &clapTrap) {
		_name = clapTrap._name;
		_hitPoints = clapTrap._hitPoints;
		_energyPoints = clapTrap._energyPoints;
		_attackDamage = clapTrap._attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap () {
	std::cout << "ClapTrap " << _name << " destroyed." << std::endl;
};

void	ClapTrap::attack(const std::string& target) {
	if (_energyPoints && _hitPoints > 0) {
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of Damage!" << std::endl;
		_energyPoints--;
	}
	else if (!_energyPoints && !_hitPoints)
		std::cout << "ClapTrap has no Hit Points and Energy left!" << std::endl;
	else if (!_energyPoints)
		std::cout << "ClapTrap has no Energy left to attack!" << std::endl;
	else if (!_hitPoints)
		std::cout << "ClapTrap has no Hit Points left to attack!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "ClapTrap " << _name << " is attacked and looses " << amount << " hit points!" << std::endl;
	_hitPoints -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (_hitPoints && _energyPoints > 0)
	{
		std::cout << "ClapTrap " << _name << " is repaired and gets " << amount << " hit points back!" << std::endl;
		_energyPoints--;
		_hitPoints += amount;
	}
	else if (_energyPoints <= 0 && _hitPoints)
		std::cout << "ClapTrap has no Energy left to repair!" << std::endl;
	else if (!_hitPoints)
		std::cout << "ClapTrap has no Hit Points left to repair!" << std::endl;
}