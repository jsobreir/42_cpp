/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 19:32:57 by jsobreir          #+#    #+#             */
/*   Updated: 2025/05/16 20:10:50 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	try
	{		
		{
			std::cout << "------- Test 1 -------" << std::endl;
			Span sp = Span(5);
			sp.addNumber(6);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		{
			std::cout << "\n------- Test 2 -------" << std::endl;
			Span sp = Span(10);
			sp.addNumber(6);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);
			int arr[] = {1, 2, 4, 6, 7};
			std::vector<int> sp1(arr, arr + sizeof(arr)/sizeof(arr[0]));
			sp.addMultipleNumber(sp1);
			std::vector<int> c = sp.getSpan();
			for (unsigned int i = 0; i < c.size(); i++) {
				std::cout << c[i] << ", ";
			}
			std::cout << std::endl;
			
		}
		{
			std::cout << "\n------- Test 3 -------" << std::endl;
			Span sp = Span(100);
			std::vector<int> v(100, 42);
			sp.addMultipleNumber(v);
			std::vector<int> c = sp.getSpan();
			for (unsigned int i = 0; i < v.size(); i++) {
				std::cout << v[i] << ", ";
			}
		}
		{
			std::cout << "\n------- Test 4 -------" << std::endl;
			Span sp = Span(100000);
			for (int i = 0; i < 100000; i++)
				sp.addNumber(rand() % 100);
			std::vector<int> c = sp.getSpan();
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		{
			std::cout << "\n------- Test 5 -------" << std::endl;
			Span sp = Span(2);
			sp.addNumber(9);
			sp.shortestSpan();
			// sp.longestSpan();
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
