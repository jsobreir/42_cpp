/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42porto.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 19:32:50 by jsobreir          #+#    #+#             */
/*   Updated: 2025/03/20 14:24:01 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
	{
		std::cout << "--------- Test 1 ---------" << std::endl;
		Bureaucrat john = Bureaucrat("John", 100);
		Intern intern;
		AForm *scf = intern.makeForm("ShrubberyCreationForm", "humous");
		std::cout << john;
		std::cout << *scf;
		john.signForm(*scf);
		john.executeForm(*scf);
		delete scf;
		std::cout << "\n";
	}
	{
		std::cout << "--------- Test 2 ---------" << std::endl;
		Bureaucrat pit = Bureaucrat("Pitt", 5);
		Intern intern;
		AForm *rrf = intern.makeForm("RobotomyRequestForm", "popi");
		std::cout << *rrf;
		pit.signForm(*rrf);
		pit.executeForm(*rrf);
		delete rrf;
		std::cout << "\n";
	}
	{
		std::cout << "--------- Test 3 ---------" << std::endl;
		Bureaucrat max = Bureaucrat("Max", 50);
		Intern intern;
		AForm *ppf = intern.makeForm("PresidentialPardonForm", "profi");
		std::cout << *ppf;
		max.executeForm(*ppf);
		max.signForm(*ppf);
		std::cout << *ppf;
		max.executeForm(*ppf);
		delete ppf;
		std::cout << "\n";
	}
}
