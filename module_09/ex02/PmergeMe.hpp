/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:50:12 by jsobreir          #+#    #+#             */
/*   Updated: 2025/05/02 20:30:26 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <deque>

class PmergeMe {
    private:
        std::vector<int> vector;
        std::deque<int> deque;
		int	_order;
	public:
        PmergeMe();
        PmergeMe(PmergeMe const &other);
        PmergeMe &operator=(PmergeMe const &other);
        ~PmergeMe();
        std::vector<int> call(const std::vector<int>& input);
        std::vector<int> merge_insert_sort(void);
		template <typename Container> void sort(Container &vec);
		template <typename Container> Container insert_sort(Container &a, Container &b);
} ;

template <typename Container>
void PmergeMe::sort(Container &vec) {
	Container a;
	Container b;

	_order++;
	Container::iterator it = vec.begin();
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
	sort(a);
	insert(a, b);
}

template <typename Container>
Container PmergeMe::insert_sort(Container &a, Container &b) {
	Container main, pend;

	main.push_back(b[0]);
	for (Container::iterator it = a.start(); it != a.end(); it++) {
		main.push_back(*it);
	}
	for (Container::iterator it = b.start() + 1 ; it != b.end(); it++) {
		pend.push_back(*it);
	}
}
