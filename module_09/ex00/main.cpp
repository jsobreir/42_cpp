/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:56:55 by jsobreir          #+#    #+#             */
/*   Updated: 2025/04/22 13:22:58 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include "BitcoinExchange.hpp"

bool hasExtension (std::string filename, const char *extension) {
    std::string ext(extension);
        if (!filename.compare(filename.size() - ext.size(), filename.size(), ext, ext.size()))
            return true;
    return false;
}

int main(int argc, char **argv)
{
    if (!argc) {
        std::cerr << "Invalid Input file: please include an input file.";
        return 0;
    }
        return 0;
    std::ofstream input;
    std::ofstream data;
    std::string filename(argv[1]);
    if (hasExtension(filename, ".txt")) {
        std::cout << "Invalid Input file: file must be of .txt format." << std::endl;
    }
    BitcoinExchange exchange;
    exchange.fillValues("./data.csv");
    exchange.convert("./input.txt");
}