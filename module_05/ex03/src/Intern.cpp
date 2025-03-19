/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42porto.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:02:08 by jsobreir          #+#    #+#             */
/*   Updated: 2025/03/06 15:08:57 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() { }

Intern::Intern(std::string name, std::string target) : _name(name), _target(target) {

}

Intern::Intern(Intern const &Intern) : _name(Intern._name) {
	*this = Intern;
}

Intern &Intern::operator=(Intern const &other) {
	if (this != &other) {
		_name = other._name;
		_target = other._target;

	}
	return *this;
}

Intern::~Intern () { }

AForm *Intern::makeForm() {
	AForm	*(form[3]) ( ) = {
		&ShrubberyCreationForm::createShrubberyCreationForm,
		&RobotomyRequestForm::createRobotomyRequestForm,
		&PresidentialPardonForm::createPresidentialPardonForm
	};
}

std::ostream& operator<<(std::ostream &out, const Intern &Intern) {
	return out;
}