/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:54:42 by jsobreir          #+#    #+#             */
/*   Updated: 2025/04/21 17:45:34 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & other) {
    *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const & other) {
    if (this != &other) {
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {
    
}


void BitcoinExchange::printValues() {
    std::map<std::string, int>::iterator it;
    for (it = _map.begin(); it != _map.end(); ++it) {
        std::cout << it->first << ": " << it->second << std::endl;
    }
}

void BitcoinExchange::fillValues(std::string fn) {
    std::ifstream db;
    db.open(fn.c_str());
    if (!db)
        std::cout << "Error, could not open file." << std::endl;
    std::string date;
    std::string rate_s;
    int rate_i;
    while (std::getline(db, date, ',') && std::getline(db, rate_s)) {
        std::stringstream rate(rate_s);
        rate >> rate_i;
        _map.insert(std::make_pair(date, rate_i));
    }
    db.close();
}

void BitcoinExchange::convert(std::string in) {
    std::ifstream inputf;
    inputf.open(in.c_str());
    std::string date;
    double value;
    std::string value_s;
    while (getline(inputf, date, ' ') && getline(inputf, value_s)) {
        std::stringstream ss(value_s);
        ss >> value;
        if (_map.find(date) != _map.end()) {
            value *= 
        }
    }
}