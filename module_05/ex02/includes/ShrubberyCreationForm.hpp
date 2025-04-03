/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42porto.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:57:20 by jsobreir          #+#    #+#             */
/*   Updated: 2025/04/03 14:57:21 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <exception>
#include <fstream>
#include "AForm.hpp"

class AForm;
class ShrubberyCreationForm : public AForm {
	private:
		std::string _target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const &ShrubberyCreationForm);
		virtual~ShrubberyCreationForm ();
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &ShrubberyCreationForm);
		std::string getName() const ;
		void execute(Bureaucrat const &executor) const ;
} ;

std::ostream& operator<<(std::ostream &out, const ShrubberyCreationForm &Bureaucrat);