/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:50:12 by jsobreir          #+#    #+#             */
/*   Updated: 2025/05/08 01:01:06 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <string>

class PmergeMe {
    private:
        std::vector<int> vector;
        std::deque<int> deque;
		int	_order;
	public:
        PmergeMe();
		PmergeMe(std::vector<int> &vec);
        PmergeMe(PmergeMe const &other);
        PmergeMe &operator=(PmergeMe const &other);
        ~PmergeMe();
        std::vector<int> call(const std::vector<int>& input);
        std::vector<int> merge_insert_sort(void);
		template <typename Container> Container sort(void);
		template <typename Container> Container insert_sort(Container &a, Container &b);
} ;

template <typename Container>
Container PmergeMe::sort(void) {
	Container vec = vector;
	Container a;
	Container b;

	_order++;
	typename Container::iterator it = vec.begin();
	for (it; it != vec.end(); it += 2) {
		if (!it) {
			Container remaining = --it;
			break;
		}
		if (vec[it + 1] < vec[it]) {
			b.push_back(vec[it + 1]); 
			a.push_back(vec[it]); 
		}
		else {
			b.push_back(vec[it]); 
			a.push_back(vec[it + 1]); 
		}
	}
	// Recursively call the function sort to sort the winners
	if (a.size())
		a = sort(a);
	return insert_sort(a, b);
}

template <typename Container>
Container PmergeMe::insert_sort(Container &a, Container &b) {
	Container main, pend;

	main.push_back(b[0]);
	for (typename Container::iterator it = a.start(); it != a.end(); it++) {
		main.push_back(*it);
	}
	for (typename Container::iterator it = b.start() + 1 ; it != b.end(); it++) {
		pend.push_back(*it);
	}
	return main;
}
