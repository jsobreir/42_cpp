/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:12:34 by jsobreir          #+#    #+#             */
/*   Updated: 2024/12/17 16:25:41 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog: public AAnimal {
	protected:
		std::string _type;
	public:
		Dog();
		Dog(const Dog &dog);
		Dog operator=(Dog const &dog);
		~Dog();
		void makeSound(void) const ;
		std::string getType(void) const ;
		void setIdea( int i, std::string idea );
		const std::string getIdea( int i );
	private:
		Brain *_brain;
} ;