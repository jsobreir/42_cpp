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

int main(void)
{
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