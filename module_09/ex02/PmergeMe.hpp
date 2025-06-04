/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:50:12 by jsobreir          #+#    #+#             */
/*   Updated: 2025/06/02 14:16:01 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <string>
#include <cmath>

#define DEBUG 0

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
	
	#if DEBUG
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
	#endif
	
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
		#if DEBUG
			std::cout << "a = " << a.back() << std::endl;
			std::cout << "b = " << b.back() << std::endl;
		#endif
		it++;
		it++;
	}
	#if DEBUG
		std::cout << "Remaining = ";
		for (typename Container::iterator it = remaining.begin(); it != remaining.end(); ++it) {
			std::cout << *it << " ,";
		}
		std::cout << std::endl;
	#endif
	if (a.size() >= 2)
		a = sort(a);
	return insert_sort(a, b, remaining);
}

template <typename Container>
Container PmergeMe::insert_sort(Container &a, Container &b, Container &c) {
	Container main, pend;
	for (typename Container::iterator it = a.begin(); it != a.end(); it++) {
		main.push_back(*it);
	}
	typename Container::iterator pos = std::lower_bound(main.begin(), main.end(), b[0]);
	main.insert(pos, b[0]);
	for (typename Container::iterator it = b.begin() + 1 ; it != b.end(); it++) {
		pend.push_back(*it);
	}
	#if DEBUG
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
	#endif
	int n = 2;
	std::vector<int> j_indices;

	while (true) {
		int jacob = calculate_jacobsthal(n);
		if ((unsigned int)jacob >= pend.size())
			break;
		j_indices.push_back(jacob);
		n++;
	}

	bool *inserted = new bool[pend.size()];
	for (size_t i = 0; i < pend.size(); ++i)
		inserted[i] = false;

	for (size_t i = 0; i < j_indices.size(); ++i)
		inserted[j_indices[i]] = true;

	for (size_t i = 0; i < pend.size(); ++i) {
		if (!inserted[i])
			j_indices.push_back(i);
	}

	delete[] inserted;

	for (typename std::vector<int>::iterator it = j_indices.begin(); it != j_indices.end(); it++) {
		typename Container::iterator pos = std::lower_bound(main.begin(), main.end(), pend[*it]);
		if ((unsigned long)*it >= pend.size())
			throw Exception();
		main.insert(pos, pend[*it]);
	}
	for (typename Container::iterator it = c.begin(); it != c.end(); ++it) {
		typename Container::iterator pos = std::lower_bound(main.begin(), main.end(), *it);
		main.insert(pos, *it);
	}
	#if DEBUG
		std::cout << "After Insertion -------" << std::endl;
		std::cout << "main = ";
		for (typename Container::iterator it = main.begin(); it != main.end(); ++it) {
			std::cout << *it << " ,";
		}
		std::cout << std::endl;
		std::cout << std::endl;
	#endif
	return main;
}

template<typename Iterator>
bool is_sorted(Iterator begin, Iterator end) {
    if (begin == end) return true;
    Iterator next = begin;
    ++next;
    while (next != end) {
        if (*next < *begin)
            return false;
        ++begin;
        ++next;
    }
    return true;
}