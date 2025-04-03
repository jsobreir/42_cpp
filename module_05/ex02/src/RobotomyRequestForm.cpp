/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42porto.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:57:38 by jsobreir          #+#    #+#             */
/*   Updated: 2025/04/03 14:57:39 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() { }

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, 72, 45) { }

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &scf) : AForm(scf.getName(), 72, 45) {
	*this = scf;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &other) {
	if (this != &other)
		_target = other._target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm () { }

std::string RobotomyRequestForm::getName() const {
	return _target;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	if (getSignStatus() == 0)
		throw FormNotSignedException();
	if (getMinExec() < executor.getGrade())
		throw GradeTooLowException();
	srand(time(0));
	int	random = rand() % 2;
	if (random == 0)
		std::cout << "driiiiiiiiiii" << std::endl;
	else
		std::cout << "Robotomy has failed" << std::endl;
}

std::ostream& operator<<(std::ostream &out, const RobotomyRequestForm &rrf) {
	out << "Form Name: " << rrf.getName() << ".\n";
	out << "Sign status: " << rrf.getSignStatus() << ".\n";
	out << "Min Sign grade: " << rrf.getMinSign() << ".\n";
	out << "Min Exec grade: " << rrf.getMinExec() << ".\n";
	return out;
}
