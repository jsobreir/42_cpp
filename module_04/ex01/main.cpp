/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:28:11 by jsobreir          #+#    #+#             */
/*   Updated: 2025/01/09 12:07:23 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	{
		std::cout << "-------- Test 1 --------" << std::endl;
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		delete j;
		delete i;
	}
	{
		std::cout << "\n-------- Test 2 --------" << std::endl;
		const Animal *array[10];
		
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
		a->setIdea(0, "I want to eat the garbage");
		a->setIdea(1, "Will my owner get mad?");
		a->setIdea(2, "Probably not, let's eat the garbage and then lick my owner");
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
		Animal animal;
	}
	return 0;
}
