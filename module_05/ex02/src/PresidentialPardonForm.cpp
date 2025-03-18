#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() {
	
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(target, 25, 5) {

}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &scf) : AForm(scf.getName(), 25, 5) {
	*this = scf;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &other) {
	if (this != &other)
		_target = other._target;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm () { }

std::string PresidentialPardonForm::getName() const {
	return _target;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	if (getSignStatus() == 0)
		throw FormNotSignedException();
	if (getMinExec() < executor.getGrade())
		throw GradeTooLowException();
	std::cout << _target << " has been pardoned by  Zaphod Beeblebrox.\n";
}

std::ostream& operator<<(std::ostream &out, const PresidentialPardonForm &rrf) {
	out << "Form Name: " << rrf.getName() << ".\n";
	out << "Sign status: " << rrf.getSignStatus() << ".\n";
	out << "Min Sign grade: " << rrf.getMinSign() << ".\n";
	out << "Min Exec grade: " << rrf.getMinExec() << ".\n";
	return out;
}
