/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:32:12 by jsobreir          #+#    #+#             */
/*   Updated: 2025/04/08 15:50:24 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdlib.h>

template <typename T>
class Array {
    private:
        T *_array;
        unsigned int _n;
    public:
        Array() {
            _n = 0;
            _array = new T;
        }
        Array(unsigned int n) {
            _n = n;
            _array = new T[_n];
        }
        Array(Array const &other) {
            _n = other._n;
            _array = new T[_n];
            for (unsigned int i = 0; i < _n; i++) {
               _array[i] = other._array[i];
            }
        }
        Array &operator=(Array const &other) {
            if (this != &other) {
                _n = other._n;
                _array = new T[_n];
                for (int i = 0; i < _n; i++) {
                    _array[i] = other._array[i];
                }
            }
            return *this;
        }
        ~Array() {
            delete[] _array;
        }
        T &operator[](unsigned int n) {
            if (n >= _n)
                throw IndexOutOfBoundsException();
            return _array[n];
        }
        unsigned int size() const {
            return _n;
        }
        class IndexOutOfBoundsException : public std::exception {
            public:
                virtual const char *what() const throw() {
                    return "Index out of bounds";
                }
        } ;
} ;
