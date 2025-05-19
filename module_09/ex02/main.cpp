/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:50:48 by jsobreir          #+#    #+#             */
/*   Updated: 2025/05/19 18:27:26 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <sys/time.h>
#include <iomanip>

int main (int argc, char **argv) {
	PmergeMe pm;
	try {
		if (argc < 2)
			throw std::runtime_error("Requires an argument list!");
		{
			int num;
			std::vector<int> numbers;
			for (int i = 1; i < argc; i++) {
				std::istringstream buffer(argv[i]);
				while (buffer >> num)
					numbers.push_back(num);
			}
			std::cout << "Before: ";
			for(long unsigned int i = 0; i < numbers.size();++i) {
				if (i == numbers.size())
					std::cout << numbers[i] << std::endl;
				else
					std::cout << numbers[i] << ',';
			}
			clock_t start = clock();
			std::vector<int> ret = pm.sort<std::vector<int> >(numbers);
			clock_t end = clock();
			
			// Print values
			std::cout << "After: ";
			for(long unsigned int i = 0; i<ret.size(); ++i) {
				if (i == numbers.size())
					std::cout << ret[i] << std::endl;
				else
					std::cout << ret[i] << ',';
			}
			long elapsed_us = 1e6 * (end - start) / CLOCKS_PER_SEC;
			std::cout << "Time to process a range of " << numbers.size()
					  << " with std::vector : " << elapsed_us << " us" << std::endl;	}
		{
			int num;
			std::deque<int> numbers;
			for (int i = 1; i < argc; i++) {
				std::istringstream buffer(argv[i]);
				while (buffer >> num)
					numbers.push_back(num);
			}
			clock_t start = clock();
			std::deque<int> ret_d = pm.sort<std::deque<int> >(numbers);
			clock_t end = clock();
			std::cout << std::endl;
			long elapsed_us = 1e6 * (end - start) / CLOCKS_PER_SEC;
			std::cout << "Time to process a range of " << numbers.size()
					  << " with std::deque : " << elapsed_us << " us" << std::endl;
			return 0;
		}
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}