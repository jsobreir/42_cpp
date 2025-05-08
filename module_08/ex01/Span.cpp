/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:11:47 by jsobreir          #+#    #+#             */
/*   Updated: 2025/05/08 16:25:24 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span () {
	_N = 0;
	_N_ocupied = 0;
}

Span::Span (int N) {
	_N = N;
	_N_ocupied = 0;
}

Span::Span (const Span & other) {
	*this = other;
}

Span &Span::operator=(Span const &other) {
	if (this != &other) {
		_N = other._N;
		_N_ocupied = other._N_ocupied;
	}
	return (*this);
}

void Span::addNumber (long unsigned int number) {
	if (_N_ocupied < _N) {
		_span.insert(_span.end(), number);
		_N_ocupied++;
	}
	else
		throw std::runtime_error("No more space left in the vector!");
}

int Span::shortestSpan() {
    if (_span.size() < 2)
        throw std::runtime_error("Need at least two numbers");
		std::vector<int> newSpan(_span);
    std::sort(newSpan.begin(), newSpan.end());
    int minSpan = longestSpan();
    for (size_t i = 1; i < newSpan.size(); ++i) {
        int diff = newSpan[i] - newSpan[i - 1];
        if (diff < minSpan)
            minSpan = diff;
    }
    return minSpan;
}

int Span::longestSpan () {
	if (_span.size() < 2)
		throw std::runtime_error("Need at least two numbers");
	int min = *std::min_element(_span.begin(), _span.end());
	int max = *std::max_element(_span.begin(), _span.end());
	return (max - min);
}

void Span::addMultipleNumber(std::vector<int> range) {
	if (range.size() + _N_ocupied <= _N) {
		_span.insert(_span.end(), range.begin(), range.end());
		_N_ocupied += range.size();
	} else
		throw std::runtime_error("No more space left in the vector!");
}

std::vector<int> Span::getSpan(void) const {
	return _span;
}

int Span::getSize(void) const {
	return _N;
}