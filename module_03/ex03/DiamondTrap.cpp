/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:28:29 by jsobreir          #+#    #+#             */
/*   Updated: 2024/12/16 16:03:51 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"), _name("Default") {
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap was created." << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name") {
	this->_name = name;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap " << this->_name << " was created." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& diamondTrap) {
	*this = diamondTrap;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& diamondTrap) {
	if (this != &diamondTrap) {
		this->_hitPoints = diamondTrap._hitPoints;
		this->_energyPoints = diamondTrap._energyPoints;
		this->_attackDamage = diamondTrap._attackDamage;		
	}
	return *this;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << _name << " destroyed." << std::endl;
}

void DiamondTrap::whoAmI() {
	std::cout << "My name is " << _name << " and my ClapTrap is " << ClapTrap::_name << std::endl;
}

void DiamondTrap::attack(const std::string& target) {
    if (_energyPoints > 0 && _hitPoints > 0) {
        std::cout << "DiamondTrap " << _name << " attacks " << target
                  << ", causing " << _attackDamage << " points of Damage!" << std::endl;
        _energyPoints--;
    } else if (_hitPoints <= 0) {
        std::cout << "DiamondTrap " << _name << " cannot attack because it has no Hit Points!" << std::endl;
    } else {
        std::cout << "DiamondTrap " << _name << " cannot attack because it has no Energy Points!" << std::endl;
    }
}