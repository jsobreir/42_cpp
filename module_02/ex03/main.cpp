/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:32:14 by jsobreir          #+#    #+#             */
/*   Updated: 2024/12/16 17:57:46 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main(void) {
	Point a(0.01, 0);
	Point b(2.5, 3.5);
	Point c(5.31, 0);
	Point point(62, 57);
	bool test1 = bsp(a, b, c, point);
	Point point2(2, 1);
	bool test2 = bsp(a, b, c, point2);
	Point point3(0, 0);
	bool test3 = bsp(a, b, c, point3);
	Point point4(0.01, 2);
	bool test4 = bsp(a, b, c, point4);
	std::cout << "Teste 1: " << test1 << std::endl;
	std::cout << "Teste 2: " << test2 << std::endl;
	std::cout << "Teste 3: " << test3 << std::endl;
	std::cout << "Teste 4: " << test4 << std::endl;

}