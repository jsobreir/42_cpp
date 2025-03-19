/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42porto.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:02:06 by jsobreir          #+#    #+#             */
/*   Updated: 2025/03/06 14:50:39 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>
#include "AForm.hpp"


class AForm;
class Bureaucrat {
	private:
		const std::string _name;
		int	_grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const &Bureaucrat);
		Bureaucrat &operator=(Bureaucrat const &Bureaucrat);
		~Bureaucrat ();
		const std::string getName() const;
		int getGrade() const ;
		void increment(int amount);
		void decrement(int amount);
		void signForm(AForm &form);
		void executeForm(AForm const & form);
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		} ;
		
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();	
		} ;
} ;

std::ostream& operator<<(std::ostream &out, const Bureaucrat &Bureaucrat);