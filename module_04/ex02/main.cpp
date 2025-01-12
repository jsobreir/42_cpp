/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:28:11 by jsobreir          #+#    #+#             */
/*   Updated: 2025/01/09 12:05:07 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "AAnimal.hpp"

int main()
{
	{
		std::cout << "-------- Test 1 --------" << std::endl;
		const AAnimal* j = new Dog();
		const AAnimal* i = new Cat();
		delete j;
		delete i;
	}
	{
		std::cout << "\n-------- Test 2 --------" << std::endl;
		const AAnimal *array[10];
		
		for (int i = 0; i < 10; i++) {
			if (i < 5)
				array[i] = new Dog();
			else
				array[i] = new Cat();
		}
		for (int i = 0; i < 10; i++) {
				delete array[i];
		}
	}
	{
		std::cout << "\n-------- Test 3 --------" << std::endl;
		std::cout << "--- Created pointer a to class Dog" << std::endl;
		Dog *a = new Dog();
		std::cout << "--- Created three ideas for Dog a:" << std::endl;
		a->setIdea(0, "I need to smell that poop");
		a->setIdea(1, "I need to pee on that tree");
		a->setIdea(2, "I need to smell the pee");
		std::cout << a->getIdea(0) << std::endl;
		std::cout << a->getIdea(1) << std::endl;
		std::cout << a->getIdea(2) << std::endl;

		std::cout <<  "--- Created pointer b to a deep copy of class a:" << std::endl;
		Dog *b = new Dog(*a);
		std::cout << "--- Both a and b make the dog sound:" << std::endl;
		a->makeSound();
		b->makeSound();
		std::cout << "--- If b is a deep copy of a then deleting a shouldnt affect b:"	<< std::endl;
		delete a;
		std::cout << "--- b still produces the dog sound:"	<< std::endl;
		b->makeSound();
		std::cout << "--- b still has the same ideas as a" << std::endl;
		std::cout << b->getIdea(0) << std::endl;
		std::cout << b->getIdea(1) << std::endl;
		std::cout << b->getIdea(2) << std::endl;
		delete b;
	}
		{
		std::cout << "\n-------- Test 4 --------" << std::endl;
		std::cout << "Cannot instatiate class AAnimal" << std::endl;
		// AAnimal aanimal; // Try to uncomment this
	}
}
