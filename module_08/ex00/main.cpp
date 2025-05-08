/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:25:51 by jsobreir          #+#    #+#             */
/*   Updated: 2025/04/07 17:58:22 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>

int main (void)
{
	int arr[] = {1, 3, 1, 56, 2};
	std::vector<int> vector(arr, arr + sizeof(arr)/sizeof(arr[0]));
	try {
		std::cout << "first occurrence: " << *easyfind(vector, 2) << std::endl;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}
