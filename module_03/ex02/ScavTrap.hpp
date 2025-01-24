/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:29:26 by jsobreir          #+#    #+#             */
/*   Updated: 2024/12/17 13:30:28 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <cmath>
#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap {
	private:

	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& scavTrap);
		ScavTrap& operator=(const ScavTrap& scavTrap);
		~ScavTrap();
		void guardGate(void);
		void attack(const std::string& target);
} ;
