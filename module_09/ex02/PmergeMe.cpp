/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 19:30:06 by jsobreir          #+#    #+#             */
/*   Updated: 2025/05/09 19:23:18 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
	_order = 0;
	std::cout << "Initialize PmergeMe with a vector of numbers!" << std::endl;
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
