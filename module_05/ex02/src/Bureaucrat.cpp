/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42porto.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:02:08 by jsobreir          #+#    #+#             */
/*   Updated: 2025/03/06 15:08:57 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() { }

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
	if (grade >= 1 && grade <= 150)
		_grade = grade;
	else if (grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	else
		throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::Bureaucrat(Bureaucrat const &Bureaucrat) : _name(Bureaucrat._name) , _grade(Bureaucrat._grade) {
	*this = Bureaucrat;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other) {
	if (this != &other)
		_grade = other._grade;
	return *this;
}

Bureaucrat::~Bureaucrat () { }

const std::string Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

void Bureaucrat::signForm(AForm &form) {
	if (form.getSignStatus() == true)
		std::cout << form.getName() << " already signed" << std::endl;
	else
	{
		if (_grade > form.getMinSign())
			std::cout << getName() << " couldn't sign form because his grade is too low" << std::endl;
		else {
			form.beSigned(*this);
			std::cout << getName() << " signed form " << form.getName() << std::endl;
		}
	}
}

void Bureaucrat::executeForm(const AForm &form) {
	if (form.getMinExec() < this->getGrade())
		std::cout << "Form " << getName() << " cannot be executed, because "
			<< this->getName() << " doesn't have the required grade\n";
	else if (form.getSignStatus() == 0)
		std::cout << "Form " << getName() << " cannot be executed, because it is not signed\n";
	else {
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	}
}

void Bureaucrat::increment(int amount) {
	int new_grade;

	new_grade = _grade - amount;
	if (new_grade >= 1 && new_grade <= 150)
		_grade -= amount;
	else if (new_grade >= 150)
		throw GradeTooLowException();
	else
		throw GradeTooHighException();
}

void Bureaucrat::decrement(int amount) {
	int new_grade;

	new_grade = _grade + amount;
	if (new_grade >= 1 && new_grade <= 150)
		_grade += amount;
	else if (new_grade >= 150)
		throw GradeTooLowException();
	else
		throw GradeTooHighException();
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

std::ostream& operator<<(std::ostream &out, const Bureaucrat &Bureaucrat) {
	out << Bureaucrat.getName() << ", Bureaucrat grade " << Bureaucrat.getGrade() << ".\n";
	return out;
}