/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42porto.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:57:16 by jsobreir          #+#    #+#             */
/*   Updated: 2025/04/03 14:57:17 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <exception>
#include <fstream>
#include <stdlib.h>
#include "AForm.hpp"

class AForm;
class PresidentialPardonForm : public AForm {
	private:
		std::string _target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const &PresidentialPardonForm);
		~PresidentialPardonForm ();
		PresidentialPardonForm &operator=(PresidentialPardonForm const &PresidentialPardonForm);
		std::string getName() const ;
		void execute(Bureaucrat const &executor) const;
} ;

std::ostream& operator<<(std::ostream &out, const PresidentialPardonForm &Bureaucrat);