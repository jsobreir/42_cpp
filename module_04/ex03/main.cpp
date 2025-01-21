/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:30:46 by jsobreir          #+#    #+#             */
/*   Updated: 2025/01/21 12:46:03 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
	{
		std::cout << "---- Test 1 ----" << std::endl;
		AMateria *cure = new Cure();
		std::cout << cure->getType() << std::endl;
		AMateria *ice = new Ice();
		std::cout << ice->getType() << std::endl;
		delete cure;
		delete ice;
	}
	{
		std::cout << "\n---- Test 2 ----" << std::endl;
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("cure");
		me->equip(tmp);
		tmp = src->createMateria("ice");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
	}
	{
		std::cout << "\n---- Test 3 ----" << std::endl;
		IMateriaSource	*srce = new MateriaSource();
		AMateria		*tmp;
		ICharacter		*bob = new Character("Bob");

		srce->learnMateria(new Ice());
		srce->learnMateria(new Cure());
		srce->learnMateria(new Ice());
		srce->learnMateria(new Cure());

		tmp = srce->createMateria("ice");
		bob->equip(tmp);
		tmp = srce->createMateria("cure");
		bob->equip(tmp);
		tmp = srce->createMateria("ice");
		bob->equip(tmp);
		
		bob->use(0, *bob);
		bob->use(1, *bob);
		bob->use(2, *bob);
		bob->use(3, *bob);

		bob->unequip(1);
		
		bob->use(0, *bob);
		bob->use(1, *bob);
		bob->use(2, *bob);

		delete srce;
		delete bob;
		return 0;
	}
}
