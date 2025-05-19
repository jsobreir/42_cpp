/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 19:30:06 by jsobreir          #+#    #+#             */
/*   Updated: 2025/05/19 18:58:30 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
	_order = 0;
}

PmergeMe::PmergeMe(std::vector<int> &vec) {
	_order = 0;
	vector = vec;
}
PmergeMe::PmergeMe(std::deque<int> &deq) {
	_order = 0;
	deque = deq;
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

const char* PmergeMe::Exception::what() const throw() {
	return "Error!";
}

int PmergeMe::calculate_jacobsthal(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	int j0 = 0, j1 = 1, jn = 0;
	for (int i = 2; i <= n; ++i) {
		jn = j1 + 2 * j0;
		j0 = j1;
		j1 = jn;
	}
	return jn;
}
