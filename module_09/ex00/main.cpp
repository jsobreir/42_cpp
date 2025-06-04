/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:56:55 by jsobreir          #+#    #+#             */
/*   Updated: 2025/06/02 14:19:33 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    try
    {
        if (argc <= 1) {
            std::cerr << "Invalid Input file: please include an input file.";
            return 0;
        }
        std::ofstream input;
        std::ofstream data;
        std::string filename(argv[1]);
        BitcoinExchange exchange;
        exchange.fillValues("./data.csv");
        exchange.convert(argv[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}