/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:50:12 by jsobreir          #+#    #+#             */
/*   Updated: 2025/05/19 19:03:26 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <string>
#include <cmath>

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
		int calculate_jacobsthal(int n);
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
	std::cout << "Recursion Level = " << _order << std::endl;
	if (it == vec.end()) {
		std::cerr << "Error!" << std::endl;
		throw Exception();
	}
	std::cout << "Main = ";
	for (typename Container::iterator it = vec.begin(); it != vec.end(); ++it) {
		std::cout << *it << " ,";
	}
	std::cout << std::endl;
	while (it != vec.end()) {
		next = it;
		next++;
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
		std::cout << "a = " << a.back() << std::endl;
		std::cout << "b = " << b.back() << std::endl;
		it++;
		it++;
	}
	std::cout << "Remaining = ";
	for (typename Container::iterator it = remaining.begin(); it != remaining.end(); ++it) {
		std::cout << *it << " ,";
	}
	std::cout << std::endl;
	if (a.size() > 2)
		a = sort(a);
	return insert_sort(a, b, remaining);
}

template <typename Container>
Container PmergeMe::insert_sort(Container &a, Container &b, Container &c) {
	Container main, pend;
	main.push_back(b[0]);
	main.push_back(a[0]);
	for (typename Container::iterator it = a.begin() + 1; it != a.end(); it++) {
		main.push_back(*it);
	}
	for (typename Container::iterator it = b.begin() + 1 ; it != b.end(); it++) {
		pend.push_back(*it);
	}
	std::cout << "Main and Pend -------" << std::endl;
	std::cout << "main = ";
	for (typename Container::iterator it = main.begin(); it != main.end(); ++it) {
		std::cout << *it << " ,";
	}
	std::cout << std::endl;
	std::cout << "pend = ";
	for (typename Container::iterator it = pend.begin(); it != pend.end(); ++it) {
		std::cout << *it << " ,";
	}
	std::cout << std::endl;
	int n = 0;
	std::vector<int> j_indices;
	while (true) {
		int jacob = calculate_jacobsthal(n);
		if ((unsigned long)jacob >= pend.size())
			break;
		j_indices.push_back(jacob);
		n++;
	}
	// std::cout << "Before Insertion -------" << std::endl;
	// std::cout << "a = ";
	// for (typename Container::iterator it = a.begin(); it != a.end(); ++it) {
	// 	std::cout << *it << " ,";
	// }
	// std::cout << std::endl;
	// std::cout << "b = ";
	// for (typename Container::iterator it = b.begin(); it != b.end(); ++it) {
	// 	std::cout << *it << " ,";
	// }
	// std::cout << std::endl;

	for (typename std::vector<int>::iterator it = j_indices.begin(); it != j_indices.end(); it++) {
		typename Container::iterator pos = std::lower_bound(main.begin(), main.end(), pend[*it]);
		std::cout << *it << std::endl;
		if ((unsigned long)*it >= pend.size())
			throw Exception();
		main.insert(pos, pend[*it]);
	}
	for (typename Container::iterator it = c.begin(); it != c.end(); ++it) {
		typename Container::iterator pos = std::lower_bound(main.begin(), main.end(), *it);
		main.insert(pos, *it);
	}
	std::cout << "After Insertion -------" << std::endl;
	std::cout << "main = ";
	for (typename Container::iterator it = main.begin(); it != main.end(); ++it) {
		std::cout << *it << " ,";
	}
	std::cout << std::endl;
	std::cout << std::endl;
	return main;
}
