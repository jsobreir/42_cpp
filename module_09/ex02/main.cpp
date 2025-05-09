/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:50:48 by jsobreir          #+#    #+#             */
/*   Updated: 2025/05/09 19:52:14 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <sys/time.h>
#include <iomanip>

int main (int argc, char **argv) {
	PmergeMe pm;
	try {
		if (argc < 2) {
			std::cerr << "Error!" << std::endl;
			return 1;
		}
		{
			
			int num;
			std::istringstream buffer(argv[1]);
			std::vector<int> numbers;
			// Fill array with parsed numbers
			while (buffer >> num)
				numbers.push_back(num);
				
			clock_t start = clock();
			std::vector<int> ret = pm.sort<std::vector<int> >(numbers);
			clock_t end = clock();
			
			for(long unsigned int i = 0; i<ret.size();++i)
				  std::cout << ret[i] << ',';
			// Print values
			std::cout << std::endl;
			long elapsed_us = 1000.0 * (end - start) / CLOCKS_PER_SEC;
			std::cout << "Time to process a range of " << numbers.size()
					  << " with std::vector : " << elapsed_us << " us" << std::endl;	}
		{
			int num;
			std::istringstream buffer2(argv[1]);
			std::deque<int> numbers;
			// Fill deque with parsed numbers
			while (buffer2 >> num)
				numbers.push_back(num);
				
			clock_t start = clock();
			std::deque<int> ret_d = pm.sort<std::deque<int> >(numbers);
			clock_t end = clock();
			
			// Print values
			for(long unsigned int i = 0; i<ret_d.size();++i)
				  std::cout << ret_d[i] << ',';
			std::cout << std::endl;
			long elapsed_us = 1000.0 * (end - start) / CLOCKS_PER_SEC;
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