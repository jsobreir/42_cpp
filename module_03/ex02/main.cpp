/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:29:15 by jsobreir          #+#    #+#             */
/*   Updated: 2024/12/16 15:29:16 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
	{
		std::cout << "=== ClapTrap Tests ===" << std::endl;

		std::cout << "----- Fenix should be created:" << std::endl;
		ClapTrap F("Fenix");

		std::cout << "----- Fenix should attack Venus causing 0 damage:" << std::endl;
		F.attack("Venus");

		std::cout << "----- Fenix should take 5 points of damage:" << std::endl;
		F.takeDamage(5);

		std::cout << "----- Fenix should be repaired by 10 points:" << std::endl;
		F.beRepaired(10);
	}
	{
		std::cout << "\n\n=== ScavTrap Tests ===" << std::endl;

		std::cout << "----- Scavie should be created:" << std::endl;
		ScavTrap S("Scavie");

		std::cout << "----- Scavie should attack Venus causing 20 damage:" << std::endl;
		S.attack("Venus");

		std::cout << "----- Scavie should enter Gatekeeper mode:" << std::endl;
		S.guardGate();
	}
	{
		std::cout << "\n\n=== FragTrap Tests ===" << std::endl;

		std::cout << "----- Fraggie should be created:" << std::endl;
		FragTrap F("Fraggie");

		std::cout << "----- Fraggie should attack Mars causing 30 damage:" << std::endl;
		F.attack("Mars");

		std::cout << "----- Fraggie should request high fives:" << std::endl;
		F.highFivesGuys();
	}
}