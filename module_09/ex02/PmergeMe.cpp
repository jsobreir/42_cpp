/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 19:30:06 by jsobreir          #+#    #+#             */
/*   Updated: 2025/05/08 15:35:04 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
	// std::cout << "Initialize PmergeMe with a vector of numbers!" << std::endl;
}

PmergeMe::PmergeMe(std::vector<int> &vec) {
	vector = vec;
}

PmergeMe::PmergeMe(PmergeMe const &other) {
    *this = other;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &other) {
    if (this != &other) {
        vector = other.vector;
        deque = other.deque;
    }
    return *this;
}

PmergeMe::~PmergeMe() {

}

// std::vector<int>  PmergeMe::call(const std::vector<int>& input) {
//     for (int i = 0; input[i]; i += 2) {
//         if (!input[i + 1]) {
//             vector.push_back(input[i + 1]);
//             break ;
//         }
//         else if (input[i] > input[i + 1]) {
//             vector.push_back(input[i]);
//             deque.push_back(input[i + 1]);
//         }
//         else {
//             deque.push_back(input[i]);
//             vector.push_back(input[i + 1]);
//         }
//     }
// 	return 
// }
