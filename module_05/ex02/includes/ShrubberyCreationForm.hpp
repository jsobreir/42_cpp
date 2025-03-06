#pragma once
#include <iostream>
#include <exception>
#include "AForm.hpp"

class AForm;
class ShrubberyCreationForm : public AForm {
	private:
		const std::string _name;
		bool  _is_signed;
		const int _s_g; //sign min grade
		const int _e_g; // execute min grade
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string name, int s_gm, int e_gm);
		ShrubberyCreationForm(ShrubberyCreationForm const &ShrubberyCreationForm);
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &ShrubberyCreationForm);
		~ShrubberyCreationForm ();
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

std::ostream& operator<<(std::ostream &out, const ShrubberyCreationForm &Bureaucrat);