/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:12:34 by jsobreir          #+#    #+#             */
/*   Updated: 2024/12/17 10:23:54 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Animal {
	protected:
		std::string _type;
	public:
		Animal();
		Animal(std::string type);
		Animal(const Animal &animal);
		Animal operator=(Animal const &animal);
		virtual ~Animal();
		virtual void makeSound(void) const ;
		std::string getType(void) const;
} ;
