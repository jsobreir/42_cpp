/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:50:12 by jsobreir          #+#    #+#             */
/*   Updated: 2025/05/09 19:22:53 by jsobreir         ###   ########.fr       */
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
		PmergeMe(std::deque<int> &vec);
        PmergeMe(PmergeMe const &other);
        PmergeMe &operator=(PmergeMe const &other);
        ~PmergeMe();
		template <typename Container> Container sort(Container vec);
		template <typename Container> Container insert_sort(Container &a, Container &b, Container &c);
		template <typename Container> bool comp(Container lh, Container rh);
		class Exception: public std::exception {
			public:
				virtual const char* what() const throw();
		};
} ;

template <typename Container>
Container PmergeMe::sort(Container vec) {
	Container a, b, remaining;
	_order++;
	typename Container::iterator it = vec.begin();
	typename Container::iterator next = it;
	if (it == vec.end()) {
		std::cerr << "Error!" << std::endl;
		throw Exception();
	}
	while (it != vec.end()) {
		next = it;
		next++;
		// std::cout << "it = " << *it << std::endl;
		if (next == vec.end()) {
			remaining.push_back(*it);
			break;
		}
		if (*it > *next) {
			b.push_back(*next); 
			a.push_back(*it); 
		}
		else {
			b.push_back(*it); 
			a.push_back(*next); 
		}
		// if (_order < 2) {
			// 	std::cout << *it << std::endl;
			// }
			it++;
			it++;
		}
	// std::cout << "O:" <<_order << std::endl;
	// std::cout << "A: " << std::endl;
	// for(long unsigned int i = 0; i<a.size();++i)
	// 	std::cout << a[i] << ',';
	// std::cout << std::endl;
	// std::cout << "B: " << std::endl;
	// for(long unsigned int i = 0; i<b.size();++i)
	// 		std::cout << b[i] << ',';
	// std::cout << std::endl;
	if (a.size() > 2)
		a = sort(a);
	return insert_sort(a, b, remaining);
}

template <typename Container>
Container PmergeMe::insert_sort(Container &a, Container &b, Container &c) {
	Container main, pend;

	main.push_back(b[0]);
	for (typename Container::iterator it = a.begin(); it != a.end(); it++) {
		main.push_back(*it);
	}
	for (typename Container::iterator it = b.begin() + 1 ; it != b.end(); it++) {
		pend.push_back(*it);
	}
	for (typename Container::iterator it = pend.begin(); it != pend.end(); ++it) {
		typename Container::iterator pos = std::lower_bound(main.begin(), main.end(), *it);
		main.insert(pos, *it);
	}
	for (typename Container::iterator it = c.begin(); it != c.end(); ++it) {
		typename Container::iterator pos = std::lower_bound(main.begin(), main.end(), *it);
		main.insert(pos, *it);
	}
	return main;
}
