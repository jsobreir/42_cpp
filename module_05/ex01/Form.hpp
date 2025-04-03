/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42porto.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:02:06 by jsobreir          #+#    #+#             */
/*   Updated: 2025/01/24 13:30:11 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;
class Form {
	private:
		const std::string _name;
		bool  _is_signed;
		const int _s_g;
		const int _e_g;
	public:
		Form();
		Form(std::string name, int s_gm, int e_gm);
		Form(Form const &Form);
		Form &operator=(Form const &Form);
		~Form ();
		void beSigned(Bureaucrat &Bureaucrat);
		std::string getName() const ;
		bool getSignStatus() const ;
		int	getMinSign() const ;
		int getMinExec() const ;
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		} ;
		
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();	
		} ;
} ;

std::ostream& operator<<(std::ostream &out, const Form &Form);