/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                      :+:      :+:    :+:   */
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
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class AForm;
class Intern {
	private:
		std::string _name;
		std::string	_target;
	public:
		Intern();
		Intern(std::string name, std::string target);
		Intern(Intern const &Intern);
		Intern &operator=(Intern const &Intern);
		~Intern ();
		AForm *makeForm();
} ;

std::ostream& operator<<(std::ostream &out, const Intern &Intern);