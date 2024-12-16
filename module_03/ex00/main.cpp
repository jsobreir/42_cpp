/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:30:35 by jsobreir          #+#    #+#             */
/*   Updated: 2024/12/16 15:34:31 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void) {
    std::cout << "=== ClapTrap Tests ===" << std::endl;

    std::cout << "----- Fenix should be created:" << std::endl;
    ClapTrap F("Fenix");

    std::cout << "----- Fenix should attack Venus causing 0 damage:" << std::endl;
    F.attack("Venus");

    std::cout << "----- Fenix should take 5 points of damage:" << std::endl;
    F.takeDamage(5);

    std::cout << "----- Fenix should be repaired by 10 points:" << std::endl;
    F.beRepaired(10);

    return 0;
}
