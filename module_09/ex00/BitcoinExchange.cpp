/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:54:42 by jsobreir          #+#    #+#             */
/*   Updated: 2025/06/02 12:02:53 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & other) {
    *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const & other) {
    if (this != &other) {
        _map = other._map;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() { }


void BitcoinExchange::printValues() {
    std::map<std::string, float>::iterator it;
    for (it = _map.begin(); it != _map.end(); ++it) {
        std::cout << it->first << ": " << it->second << std::endl;
    }
}

void BitcoinExchange::fillValues(std::string fn) {
    std::ifstream db;
    db.open(fn.c_str());
    if (!db) {
        std::cout << "Error, could not open data file." << std::endl;
        throw std::exception();
    }
    std::string date;
    std::string rate_s;
    double rate_i;
    while (std::getline(db, date, ',') && std::getline(db, rate_s)) {
        std::stringstream rate(rate_s);
        rate >> rate_i;
        _map.insert(std::make_pair(date, rate_i));
    }
    db.close();
}

bool BitcoinExchange::checkValidDate(std::string &date) {
    struct tm tm;
	if(strptime(date.c_str(), "%Y-%m-%d", &tm) == NULL)
	{
		return false;
	}
	return true;
}

void BitcoinExchange::convert(std::string in) {
    std::ifstream inputf;
    inputf.open(in.c_str());
    if (!inputf) {
        std::cout << "Error, could not open input file." << std::endl;
        throw std::exception();   
    }
    std::string line;
    std::getline(inputf, line);
    while (std::getline(inputf, line)) {
        std::istringstream iss(line);
        std::string date;
        std::string value_s;
        std::string msg;
        try
        {
            if (std::getline(iss, date, '|') && std::getline(iss, value_s)) {
                    float value;
                    value_s = value_s.erase(value_s.find_last_not_of(" \t\r\n") + 1);
                    std::stringstream ss(value_s);
                    ss >> value;
                    if (value < 0) {
                        throw NegativeNumberException();
                        continue;
                    }
                    else if (value > 1000) {
                        throw NumberTooLargeException();
                        continue;
                    }
                    if (!checkValidDate(date)) {
                        msg = date;
                        throw BadInputException();
                        continue;
                    }
                    std::map<std::string, float>::iterator it = _map.find(date);
                    if (it != _map.end())
                        value *= it->second;
                    it = _map.lower_bound(date);
                    if (it != _map.end()) {
                        it--;
                        value *= it->second;
                    }
                    else
                        std::cerr << "Error: No exchange rate found for this date." << std::endl;
                    std::cout << date << " => " << value_s << " = " << value << std::endl;
            }
            else {
                msg = date;
                throw BadInputException();
            }
        }
        catch(const std::exception& e) {
            std::cerr << "Error: " << e.what();
            if (msg.size() > 0) {
                std::cout << " => " << msg;
                msg.clear();
            }
            std::cout << std::endl;
        }
    }
}
const char* BitcoinExchange::BadInputException::what() const throw() {
    return "bad input";
}

const char* BitcoinExchange::NumberTooLargeException::what() const throw() {
    return "too large a number.";
}

const char* BitcoinExchange::NegativeNumberException::what() const throw() {
    return "not a positive number.";
}