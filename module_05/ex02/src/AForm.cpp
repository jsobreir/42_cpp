/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42porto.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:02:08 by jsobreir          #+#    #+#             */
/*   Updated: 2025/01/24 13:31:01 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _s_g(100) , _e_g(100) {
	_is_signed = false;
}

AForm::AForm(std::string name, int s_gm, int e_gm) 
	: _name(name) , _is_signed(false) , _s_g(s_gm) , _e_g(e_gm) {
		if (s_gm < 1)
			throw GradeTooHighException();
		else if (s_gm > 150)
			throw GradeTooLowException();
}

AForm::AForm(AForm const &form) :_name(form._name) , _s_g(form._s_g) , _e_g(form._e_g) {
	*this = form;
	_is_signed = false;
}

AForm &AForm::operator=(AForm const &other) {
	if (this != &other)
	{
		_is_signed = false;
	}
	return *this;
}

AForm::~AForm () { }

std::string AForm::getName() const {
	return _name;
}

bool AForm::getSignStatus() const {
	return _is_signed;
}

int	AForm::getMinSign() const {
	return _s_g;
}

int AForm::getMinExec() const {
	return _e_g;
}


void AForm::beSigned(Bureaucrat &Bureaucrat) {
	if (Bureaucrat.getGrade() <= _s_g)
		_is_signed = true;
	else if (Bureaucrat.getGrade() > _s_g)
		throw GradeTooLowException();
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "Grade is too low ";
}

const char* AForm::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

std::ostream& operator<<(std::ostream &out, const AForm &form) {
	out << "AForm's name: " << form.getName() << "\n"
	<< "Sign status: " << form.getSignStatus()<< "\n"	
	<< "Minimum grade to be signed: " << form.getMinSign() << "\n"
	<< "Minimum grade to be executed: " << form.getMinSign() << "\n";
	return out;
}