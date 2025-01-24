/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureocrat.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42porto.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:02:08 by jsobreir          #+#    #+#             */
/*   Updated: 2025/01/24 13:31:01 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureocrat.hpp"

Bureocrat::Bureocrat() {
	
}

Bureocrat::Bureocrat(std::string name, int grade) : _name(name) {
	if (grade >= 1 && grade <= 150)
		_grade = grade;
	else if (grade >= 150)
		throw Bureocrat::GradeTooLowException();
	else
		throw Bureocrat::GradeTooHighException();
}

Bureocrat::Bureocrat(Bureocrat const &bureocrat) : _name(bureocrat._name) , _grade(bureocrat._grade) {
	*this = bureocrat;
}

Bureocrat &Bureocrat::operator=(Bureocrat const &other) {
	if (this != &other)
	{
		_grade = other._grade;
	}
	return *this;
}

Bureocrat::~Bureocrat () { }

const std::string Bureocrat::getName() const {
	return _name;
}

int Bureocrat::getGrade() const {
	return _grade;
}

void Bureocrat::increment(int amount) {
	int new_grade;

	new_grade = _grade - amount;
	if (new_grade >= 1 && new_grade <= 150)
		_grade -= amount;
	else if (new_grade >= 150)
		throw GradeTooLowException();
	else
		throw GradeTooHighException();
}

void Bureocrat::decrement(int amount) {
	int new_grade;

	new_grade = _grade + amount;
	if (new_grade >= 1 && new_grade <= 150)
		_grade += amount;
	else if (new_grade >= 150)
		throw GradeTooLowException();
	else
		throw GradeTooHighException();
}

const char* Bureocrat::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

const char* Bureocrat::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

std::ostream& operator<<(std::ostream &out, const Bureocrat &bureocrat) {
	out << bureocrat.getName() << ", bureocrat grade " << bureocrat.getGrade() << ".\n";
	return out;
}