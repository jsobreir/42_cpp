/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 19:32:50 by jsobreir          #+#    #+#             */
/*   Updated: 2025/03/19 15:35:20 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	{
		std::cout << "--------- Test 1 ---------" << std::endl;
		Bureaucrat john = Bureaucrat("John", 100);
		ShrubberyCreationForm *shrubbery = new ShrubberyCreationForm("arbusto");
		std::cout << john;
		std::cout << *shrubbery;
		john.signForm(*shrubbery);
		john.executeForm(*shrubbery);
		delete shrubbery;
		std::cout << "\n";
	}
	{
		std::cout << "--------- Test 2 ---------" << std::endl;
		Bureaucrat pit = Bureaucrat("Pitt", 5);
		std::cout << pit;
		AForm *robotomize = new RobotomyRequestForm("robotomize");
		std::cout << *robotomize;
		pit.signForm(*robotomize);
		pit.executeForm(*robotomize);
		delete robotomize;
		std::cout << "\n";
	}
	{
		std::cout << "--------- Test 3 ---------" << std::endl;
		Bureaucrat max = Bureaucrat("Max", 50);
		std::cout << max;
		AForm *presidential = new PresidentialPardonForm("presidential");
		std::cout << *presidential;
		max.executeForm(*presidential);
		max.signForm(*presidential);
		std::cout << *presidential;
		max.executeForm(*presidential);
		delete presidential;
		std::cout << "\n";
	}
}
