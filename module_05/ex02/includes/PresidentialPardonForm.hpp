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