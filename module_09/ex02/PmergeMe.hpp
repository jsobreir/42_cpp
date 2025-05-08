/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:50:12 by jsobreir          #+#    #+#             */
/*   Updated: 2025/05/08 15:41:20 by jsobreir         ###   ########.fr       */
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
		template <typename Container> Container sort(Container vec);
		template <typename Container> Container insert_sort(Container &a, Container &b);
} ;

template <typename Container>
Container PmergeMe::sort(Container vec) {
	Container a, b, remaining;

	_order++;
	typename Container::iterator it = vec.begin();
	typename Container::iterator next = it;
	while (it != vec.end()) {
		next++;
		if (*next < *it) {
			b.push_back(*next); 
			a.push_back(*it); 
		}
		else {
			b.push_back(*it); 
			a.push_back(*next); 
		}
		it = next;
		if (next == vec.end())
			remaining.push_back(*it);
		std::cout << *it << std::endl;
		std::cout << *next << std::endl;

	}
	if (a.size())
		a = sort(a);
	return insert_sort(a, b);
}

template <typename Container>
Container PmergeMe::insert_sort(Container &a, Container &b) {
	Container main, pend;

	main.push_back(b[0]);
	for (typename Container::iterator it = a.begin(); it != a.end(); it++) {
		main.push_back(*it);
	}
	for (typename Container::iterator it = b.begin() + 1 ; it != b.end(); it++) {
		pend.push_back(*it);
	}
	return main;
}
