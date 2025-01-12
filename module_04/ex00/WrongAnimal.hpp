/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:22:17 by jsobreir          #+#    #+#             */
/*   Updated: 2024/12/17 10:06:42 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class WrongAnimal {
	protected:
		std::string _type;
	public:
		WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal &wrongAnimal);
		WrongAnimal operator=(WrongAnimal const &wrongAnimal);
		~WrongAnimal();
		void makeSound(void) const ;
		std::string getType(void) const;
} ;
