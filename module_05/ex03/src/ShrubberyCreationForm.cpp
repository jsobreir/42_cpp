#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() {
	
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target, 145, 137), _target(target) {

}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &scf) : AForm(scf.getName(), 145, 137) {
	*this = scf;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other) {
	if (this != &other)
		_target = other._target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm () { }

AForm *ShrubberyCreationForm::createShrubberyCreationForm (std::string const & target) {
	return (new ShrubberyCreationForm(target));
}

std::string ShrubberyCreationForm::getName() const {
	return _target;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	if (getSignStatus() == 0)
		throw FormNotSignedException();
	if (getMinExec() < executor.getGrade())
		throw GradeTooLowException();
	std::string name = _target + "_shrubbery";
	const char	*filename = name.c_str();
	std::ofstream file(filename);
	std::string tree;

	tree = "\
      &&&  \n\
     &&&&&  \n\
    &&&&&&&  \n\
   &&&&&&&&&  \n\
  &&&&&&&&&&&  \n\
     |||||  \n\
     |||||    \n";
	file << tree;
	file.close();
}

std::ostream& operator<<(std::ostream &out, const ShrubberyCreationForm &scf) {
	out << "Form Name: " << scf.getName() << ".\n";
	out << "Sign status: " << scf.getSignStatus() << ".\n";
	out << "Min Sign grade: " << scf.getMinSign() << ".\n";
	out << "Min Exec grade: " << scf.getMinExec() << ".\n";
	return out;
}
