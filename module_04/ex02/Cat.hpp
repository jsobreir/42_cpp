/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:12:34 by jsobreir          #+#    #+#             */
/*   Updated: 2024/12/17 16:25:10 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat: public AAnimal {
	protected:
		std::string _type;
	public:
		Cat();
		Cat(const Cat &cat);
		Cat operator=(Cat const &cat);
		~Cat();
		void makeSound(void) const ;
		std::string getType(void) const ;
	private:
		Brain *_brain;
} ;