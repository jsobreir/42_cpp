/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:18:35 by jsobreir          #+#    #+#             */
/*   Updated: 2025/05/08 14:38:54 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        typedef std::stack<T> stack;
        typedef typename stack::container_type container;
        typedef typename container::iterator iterator;
        MutantStack(){}
        ~MutantStack(){}
        MutantStack(const MutantStack &stack) {
            *this = stack;
        }
		MutantStack &operator=(MutantStack const &other) {
			if (this != &other)
				*this  = other;
			return *this;
		}
        iterator begin() {
            return this->c.begin();
        }
        iterator end() {
            return this->c.end();
        }
};
