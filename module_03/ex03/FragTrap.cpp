/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:28:20 by jsobreir          #+#    #+#             */
/*   Updated: 2024/12/16 15:28:21 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 30;
	std::cout << "FragTrap was created." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	_name = name;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 30;
	std::cout << "FragTrap " << _name << "  was created." << std::endl;
}

FragTrap::FragTrap(const FragTrap& fragTrap) {
	*this = fragTrap;
}

FragTrap& FragTrap::operator=(const FragTrap& fragTrap) {
	if (this != &fragTrap) {
		_name = fragTrap._name;
		_hitPoints = fragTrap._hitPoints;
		_energyPoints = fragTrap._energyPoints;
		_attackDamage = fragTrap._attackDamage;
	}
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap "  << _name << " destroyed." << std::endl; 
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << _name << " requests high fives from everyone!" << std::endl;
}
