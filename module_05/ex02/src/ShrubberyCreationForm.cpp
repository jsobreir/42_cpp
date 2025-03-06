#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() {
	
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name, int grade) : AForm(name, 145, 137) {

}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &scf) : _name(scf._name) , _grade(scf._grade) {
	*this = scf;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other) {
	if (this != &other)
	{
		_isSigned
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm () { }

const std::string ShrubberyCreationForm::getName() const {
	return _name;
}

int ShrubberyCreationForm::getGrade() const {
	return _grade;
}

void ShrubberyCreationForm::signForm(Form &form) {
	if (form.getSignStatus() == true)
		std::cout << getName() << " already signed" << form.getName() << std::endl;
	else
	{
		if (_grade > form.getMinSign())
			std::cout << getName() << " couldn't sign form because his grade is too low" << std::endl;
		else {
			form.beSigned(*this);
			std::cout << getName() << " signed form " << form.getName() << std::endl;
		}
	}
}


void ShrubberyCreationForm::increment(int amount) {
	int new_grade;

	new_grade = _grade - amount;
	if (new_grade >= 1 && new_grade <= 150)
		_grade -= amount;
	else if (new_grade >= 150)
		throw GradeTooLowException();
	else
		throw GradeTooHighException();
}

void ShrubberyCreationForm::decrement(int amount) {
	int new_grade;

	new_grade = _grade + amount;
	if (new_grade >= 1 && new_grade <= 150)
		_grade += amount;
	else if (new_grade >= 150)
		throw GradeTooLowException();
	else
		throw GradeTooHighException();
}

const char* ShrubberyCreationForm::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

const char* ShrubberyCreationForm::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

std::ostream& operator<<(std::ostream &out, const ShrubberyCreationForm &Bureaucrat) {
	out << Bureaucrat.getName() << ", Bureaucrat grade " << Bureaucrat.getGrade() << ".\n";
	return out;
}
