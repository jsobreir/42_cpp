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

Intern::Intern(Intern const &Intern) {
	*this = Intern;
}

Intern &Intern::operator=(Intern const &other) {
	(void)other;
	return *this;
}

Intern::~Intern () { }

AForm *Intern::makeForm(std::string name, std::string target) {
	std::string forms[3] = {
		"ShrubberyCreationForm",
		"RobotomyRequestForm",
		"PresidentialPardonForm"};

	AForm	*(*form[3]) (std::string const &) = {
		&ShrubberyCreationForm::createShrubberyCreationForm,
		&RobotomyRequestForm::createRobotomyRequestForm,
		&PresidentialPardonForm::createPresidentialPardonForm
	};
	for (int i = 0; i < 3; i++) {
		if (name == forms[i])
			return form[i](target);
	}
	return 0;
}