/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42porto.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 19:32:50 by jsobreir          #+#    #+#             */
/*   Updated: 2025/01/24 13:31:46 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureocrat.hpp"

int main(void)
{
	try
	{
		Bureocrat john = Bureocrat("John", 46);
		std::cout << john;
		john.increment(124);
	}
	catch (const std::exception& e)
	{
		std::cerr << "exception caught: " << e.what() << std::endl;
	}	
}