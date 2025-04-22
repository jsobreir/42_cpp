/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:54:40 by jsobreir          #+#    #+#             */
/*   Updated: 2025/04/22 12:38:54 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

class BitcoinExchange {
    public:
        BitcoinExchange();
        BitcoinExchange(BitcoinExchange const & other);
        BitcoinExchange &operator=(BitcoinExchange const & other);
        ~BitcoinExchange();
        void fillValues(std::string fn);
        void printValues();
        void convert(std::string in);
        bool checkValidDate(std::string &date);
        class BadInputException : public std::exception {
            public:
                virtual const char * what() const throw();
        } ;
        class NumberTooLargeException : public std::exception {
            public:
                virtual const char * what() const throw();
        } ;
        class NegativeNumberException : public std::exception {
            public:
                virtual const char * what() const throw();
        } ;
    private:
          std::map<std::string, float> _map; 
} ;