/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:10:17 by jsobreir          #+#    #+#             */
/*   Updated: 2024/12/17 16:09:02 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
}

Brain::Brain(const Brain &brain) {
	std::cout << "Brain constructor called" << std::endl;
	*this = brain;
}

Brain& Brain::operator=(const Brain &brain) {
	std::cout << "Brain assignment operator called" << std::endl;
	if (this != &brain) {
		for (int i = 0; i < 100; i++) {
			if (brain._ideas[i].length() <= 0)
				break;
			setIdea(i, brain._ideas[i]);
		}
	}
	return *this;
}

Brain::~Brain() {
}

void Brain::setIdea( int i, std::string idea ) {
	_ideas[i] = idea;
}

const std::string Brain::getIdea( int i ) {
	return _ideas[i];
}
