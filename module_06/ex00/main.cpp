/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42porto.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:00:16 by jsobreir          #+#    #+#             */
/*   Updated: 2025/03/25 15:00:17 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv) {

	if (argc == 1) {
		std::cout << "Usage: ./convert [value]" << std::endl;
		return 0;
	}
	ScalarConverter convert(argv[1]);
	return 1;
}
