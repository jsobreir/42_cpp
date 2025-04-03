/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42porto.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 19:32:50 by jsobreir          #+#    #+#             */
/*   Updated: 2025/04/03 13:58:21 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	{
		std::cout << "----- Test 1 -----" << std::endl;
		try
		{
			Bureaucrat john = Bureaucrat("John", 12);
			Form		irs = Form("IRS", 22, 45);
			std::cout << john;
			john.signForm(irs);
			john.increment(11);
			john.signForm(irs);
			std::cout << "irs signed? " << irs.getSignStatus() << std::endl;
			john.decrement(127);
			john.signForm(irs);
		}
		catch (const std::exception& e)
		{
			std::cerr << "exception caught: " << e.what() << std::endl;
		}	
	}
	{
		std::cout << "----- Test 2 -----" << std::endl;
		try
		{
			Bureaucrat john = Bureaucrat("John", 12);
			Form		irs = Form("IRS", 22, 45);
			std::cout << john;
			john.decrement(12);
			john.signForm(irs);
			std::cout << "irs signed? " << irs.getSignStatus() << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cerr << "exception caught: " << e.what() << std::endl;
		}	
	}
}