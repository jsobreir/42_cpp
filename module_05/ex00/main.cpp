/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42porto.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 19:32:50 by jsobreir          #+#    #+#             */
/*   Updated: 2025/04/03 13:46:28 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	{
		std::cout << "-------- Test Grade Too High --------" << std::endl;
		try
		{
			Bureaucrat john = Bureaucrat("John", 46);
			std::cout << john;
			john.increment(124);
		}
		catch (const std::exception& e)
		{
			std::cerr << "exception caught: " << e.what() << std::endl;
		}	
	}
	{
		std::cout << "-------- Test Grade Too Low --------" << std::endl;
		try
		{
			Bureaucrat john = Bureaucrat("John", 46);
			std::cout << john;
			john.decrement(124);
		}
		catch (const std::exception& e)
		{
			std::cerr << "exception caught: " << e.what() << std::endl;
		}	
	}
	{
		std::cout << "-------- Test Increment --------" << std::endl;
		try
		{
			Bureaucrat john = Bureaucrat("John", 46);
			std::cout << john;
			john.increment(12);
			std::cout << john;
		}
		catch (const std::exception& e)
		{
			std::cerr << "exception caught: " << e.what() << std::endl;
		}
	}
	{
		std::cout << "-------- Test Decrement --------" << std::endl;
		try
		{
			Bureaucrat john = Bureaucrat("John", 46);
			std::cout << john;
			john.decrement(12);
			std::cout << john;
		}
		catch (const std::exception& e)
		{
			std::cerr << "exception caught: " << e.what() << std::endl;
		}
	}
}