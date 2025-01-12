/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:12:34 by jsobreir          #+#    #+#             */
/*   Updated: 2024/12/18 11:16:13 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class AAnimal {
	protected:
		std::string _type;
	public:
		AAnimal();
		AAnimal(std::string type);
		AAnimal(const AAnimal &aanimal);
		AAnimal& operator=(AAnimal const &aanimal);
		virtual ~AAnimal();
		virtual void makeSound(void) const = 0;
		std::string getType(void) const;
} ;
