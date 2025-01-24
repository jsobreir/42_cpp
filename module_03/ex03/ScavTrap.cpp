/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:27:50 by jsobreir          #+#    #+#             */
/*   Updated: 2024/12/18 11:59:20 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap was created." << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	_name = name;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap " << _name << "  was created." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& scavTrap) : ClapTrap(scavTrap) {
	*this = scavTrap;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& scavTrap) {
	if (this != &scavTrap) {
		_name = scavTrap._name;
		_hitPoints = scavTrap._hitPoints;
		_energyPoints = scavTrap._energyPoints;
		_attackDamage = scavTrap._attackDamage;
	}
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap "  << _name << " destroyed." << std::endl; 
}

void ScavTrap::guardGate(void) {
	std::cout << "ScavTrap" << _name << " is in Gate keeper mode." << std::endl;
}

void ScavTrap::attack(const std::string& target) {
	if (_energyPoints && _hitPoints > 0) {
		std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of Damage!" << std::endl;
		_energyPoints--;
	}
	else if (!_energyPoints && !_hitPoints)
		std::cout << "ScavTrap has no Hit Points and Energy left!" << std::endl;
	else if (!_energyPoints)
		std::cout << "ScavTrap has no Energy left to attack!" << std::endl;
	else if (!_hitPoints)
		std::cout << "ScavTrap has no Hit Points left to attack!" << std::endl;			
}