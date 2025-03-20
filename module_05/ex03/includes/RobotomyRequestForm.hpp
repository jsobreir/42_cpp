#pragma once
#include <iostream>
#include <exception>
#include <fstream>
#include <stdlib.h>
#include "AForm.hpp"
#include <cstdlib>  // For srand() and rand()
#include <ctime>    // For time()


class AForm;
class RobotomyRequestForm : public AForm {
	private:
		std::string _target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const &RobotomyRequestForm);
		~RobotomyRequestForm ();
		static AForm *createRobotomyRequestForm(std::string const & target);
		RobotomyRequestForm &operator=(RobotomyRequestForm const &RobotomyRequestForm);
		std::string getName() const ;
		void execute(Bureaucrat const &executor) const ;
} ;

std::ostream& operator<<(std::ostream &out, const RobotomyRequestForm &Bureaucrat);