/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:54:40 by jsobreir          #+#    #+#             */
/*   Updated: 2025/04/21 16:53:34 by jsobreir         ###   ########.fr       */
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
    private:
          std::map<std::string, int> _map; 
} ;