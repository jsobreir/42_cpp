/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42porto.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:00:43 by jsobreir          #+#    #+#             */
/*   Updated: 2025/03/26 12:34:57 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base () { };

Base *generate(void) {
	srand(time(0));
	int	random = rand() % 3;
	switch (random) {
		case (0):
			return new A();
		case (1):
			return new B();
		case (2):
			return new C();
		default:
			return NULL;
	}
}

void identify(Base *p) {
	if (dynamic_cast <A*> (p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast <B*> (p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast <C*> (p))
		std::cout << "C" << std::endl;
	else
		std::cout << "No class" << std::endl;
}

void identify(Base &p) {

	try {
		(void) dynamic_cast <A &> (p);
		std::cout << "A" << std::endl;
		return ;
	} catch (std::exception &e) {}
	try {
		(void) dynamic_cast <B &> (p);
		std::cout << "B" << std::endl;
		return ;
	} catch (std::exception &e) {}
	try {
		(void) dynamic_cast <C &> (p);
		std::cout << "C" << std::endl;
		return ;
	} catch (std::exception &e) {}
}
