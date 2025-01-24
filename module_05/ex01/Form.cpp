/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42porto.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:02:08 by jsobreir          #+#    #+#             */
/*   Updated: 2025/01/24 13:31:01 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _s_g(100) , _e_g(100) {
	_is_signed = false;
}

Form::Form(std::string name, int s_gm, int e_gm) 
	: _name(name) , _is_signed(false) , _s_g(s_gm) , _e_g(e_gm) {
		if (s_gm < 1)
			throw GradeTooHighException();
		else if (s_gm > 150)
			throw GradeTooLowException();
}

Form::Form(Form const &form) :_name(form._name) , _s_g(form._s_g) , _e_g(form._e_g) {
	*this = form;
	_is_signed = false;
}

Form &Form::operator=(Form const &other) {
	if (this != &other)
	{
		_is_signed = false;
	}
	return *this;
}

Form::~Form () { }

std::string Form::getName() const {
	return _name;
}

bool Form::getSignStatus() const {
	return _is_signed;
}

int	Form::getMinSign() const {
	return _s_g;
}

int Form::getMinExec() const {
	return _e_g;
}


void Form::beSigned(Bureocrat &bureocrat) {
	if (bureocrat.getGrade() <= _s_g)
		_is_signed = true;
	else if (bureocrat.getGrade() > _s_g)
		throw GradeTooLowException();
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Grade is too low ";
}

const char* Form::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

std::ostream& operator<<(std::ostream &out, const Form &form) {
	out << "Form's name: " << form.getName() << "\n"
	<< "Sign status: " << form.getSignStatus()<< "\n"	
	<< "Minimum grade to be signed: " << form.getMinSign() << "\n"
	<< "Minimum grade to be executed: " << form.getMinSign() << "\n";
}