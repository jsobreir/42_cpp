/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:11:47 by jsobreir          #+#    #+#             */
/*   Updated: 2025/04/09 18:02:35 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span () {
	_N = 0;
	_N_ocupied = 0;
};

Span::Span (int N) {
	_N = N;
	_N_ocupied = 0;
};

Span::Span (const Span & other) {
	*this = other;
};

Span &Span::operator=(Span const &other) {
	if (this != &other) {
		_N = other._N;
		_N_ocupied = other._N_ocupied;
	}
	return (*this);
};

void Span::addNumber (long unsigned int number) {
	if (_N_ocupied < _N) {
		_span.insert(_span.end(), number);
		_N_ocupied++;
	}
	else
		throw NoMoreSpaceException();
} ;

int Span::shortestSpan () {
	int shortestSpan = longestSpan();
	for (unsigned int i = 0; i < _span.size(); i++) {
		for (unsigned int j = i + 1; j < _span.size(); j++) {
			int diff = _span[i] - _span[j];
			if (diff < 0)
				diff *= -1;
			if (diff < shortestSpan)
				shortestSpan = diff;
		}
	}
	return shortestSpan;
};

int Span::longestSpan () {
	int min = *std::min_element(_span.begin(), _span.end());
	int max = *std::max_element(_span.begin(), _span.end());
	return (max - min);
};

void Span::addMultipleNumber(std::vector<int> range) {
	if (range.size() + _N_ocupied <= _N) {
		_span.insert(_span.end(), range.begin(), range.end());
		_N_ocupied += range.size();
	} else
		throw NoMoreSpaceException();
}

std::vector<int> Span::getSpan(void) const {
	return _span;
}

int Span::getSize(void) const {
	return _N;
}

const char *Span::NoMoreSpaceException::what() const throw() {
	return "No space to add another number!";
}