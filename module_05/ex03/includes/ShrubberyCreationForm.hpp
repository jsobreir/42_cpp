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
		static AForm *createShrubberyCreationForm(std::string const & target);
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &ShrubberyCreationForm);
		std::string getName() const ;
		void execute(Bureaucrat const &executor) const ;
} ;

std::ostream& operator<<(std::ostream &out, const ShrubberyCreationForm &Bureaucrat);