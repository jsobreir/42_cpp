/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:50:48 by jsobreir          #+#    #+#             */
/*   Updated: 2025/05/08 01:02:23 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main (int argc, char **argv) {
	PmergeMe pm;
    if (argc != 2) {
        std::cerr << "Error!" << std::endl;
        return 1;
    }
	std::istringstream buffer(argv[1]);
	int num;
	std::vector<int> numbers;
	while (buffer >> num)
	numbers.push_back(num);
	pm.sort();
	return 0;
}