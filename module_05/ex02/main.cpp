/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42porto.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 19:32:50 by jsobreir          #+#    #+#             */
/*   Updated: 2025/03/06 15:09:26 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	try
	{
		Bureaucrat john = Bureaucrat("John", 12);
		AForm *shrub = new ShrubberyCreationForm("arbusto", 22, 45);
		std::cout << john;
		john.signForm(*shrub);
		john.increment(124);
		john.signForm(*shrub);
		std::cout << "shrub signed? " << (*shrub).getSignStatus() << std::endl;
		john.decrement(127);
		john.signForm(*shrub);
		john.executeForm(*shrub);
	}
	catch (const std::exception& e)
	{
		std::cerr << "exception caught: " << e.what() << std::endl;
	}	
}