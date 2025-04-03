/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42porto.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:57:13 by jsobreir          #+#    #+#             */
/*   Updated: 2025/04/03 14:57:14 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <exception>
#include <fstream>
#include <stdlib.h>
#include "AForm.hpp"

class AForm;
class RobotomyRequestForm : public AForm {
	private:
		std::string _target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const &RobotomyRequestForm);
		~RobotomyRequestForm ();
		RobotomyRequestForm &operator=(RobotomyRequestForm const &RobotomyRequestForm);
		std::string getName() const ;
		void execute(Bureaucrat const &executor) const ;
} ;

std::ostream& operator<<(std::ostream &out, const RobotomyRequestForm &Bureaucrat);