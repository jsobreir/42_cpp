/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:56:55 by jsobreir          #+#    #+#             */
/*   Updated: 2025/04/21 16:52:23 by jsobreir         ###   ########.fr       */
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
    (void)argc;
    std::ofstream input;
    std::ofstream data;
    std::string filename(argv[1]);
    if (hasExtension(filename, ".txt")) {
        std::cout << "File must be of .txt format" << std::endl;
    }
    BitcoinExchange exchange;
    exchange.fillValues("./data.csv");
}