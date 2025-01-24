/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureocrat.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42porto.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:02:06 by jsobreir          #+#    #+#             */
/*   Updated: 2025/01/24 14:09:30 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>
#include "Form.hpp"

class Form;
class Bureocrat {
	private:
		const std::string _name;
		int	_grade;
	public:
		Bureocrat();
		Bureocrat(std::string name, int grade);
		Bureocrat(Bureocrat const &bureocrat);
		Bureocrat &operator=(Bureocrat const &bureocrat);
		~Bureocrat ();
		const std::string getName() const;
		int getGrade() const ;
		void increment(int amount);
		void decrement(int amount);
		void signForm(Form const &form);
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		} ;
		
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();	
		} ;
} ;

std::ostream& operator<<(std::ostream &out, const Bureocrat &bureocrat);