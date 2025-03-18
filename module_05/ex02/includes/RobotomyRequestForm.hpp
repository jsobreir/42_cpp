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