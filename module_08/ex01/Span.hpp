/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:11:43 by jsobreir          #+#    #+#             */
/*   Updated: 2025/04/09 18:02:12 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>  

class Span {
	private:
		unsigned int _N;
		unsigned int _N_ocupied;
		std::vector<int> _span;
	public:
		Span ();
		Span (int N);
		Span (const Span & other);
		Span &operator=(Span const &other);
		void addNumber (long unsigned int number);
		int shortestSpan ();
		int longestSpan ();
		void addMultipleNumber(std::vector<int> range);
		std::vector<int> getSpan(void) const;
		int getSize(void) const;
		class NoMoreSpaceException {
			public:
				virtual const char *what() const throw();
		} ;
} ;