/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 12:51:27 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/26 17:04:55 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ICharacter.hpp"
#include "Character.hpp"
// #include "AMateria.hpp"
// #include "IMateriaSource.hpp"
#include "ICharacter.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

int main()
{
	AMateria* cureMat = new Cure();
	AMateria* cureMat2 = cureMat->clone();
	AMateria* cureIce = new Ice();
	AMateria* cureIce2 = cureIce->clone();

	std::cout << "cureMat:  " << cureMat->getType() << "\n"
			<<   "cureMat2: " << cureMat2->getType()  << "\n"
			<<   "cureIce:  " << cureIce->getType()  << "\n"
			<<   "cureIce2: " << cureIce2->getType()  << "\n"
			<< std::endl;

	ICharacter* John = new Character("John");
	ICharacter* Mark = new Character("Mark");
	John->equip(cureIce);
	John->equip(cureMat);
	John->report();
	John->use(0,*Mark);
	John->use(1, *Mark);
	John->report();
	
	delete cureIce;
	delete cureIce2;
	delete cureMat;
	delete cureMat2;
	delete John;
	delete Mark;
	return 0;
}

// 	IMateriaSource* src = new MateriaSource();
// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());
	
// 	ICharacter* me = new Character("me");
// 	AMateria* tmp;
// 	tmp = src->createMateria("ice");
// 	me->equip(tmp);
// 	tmp = src->createMateria("cure");
// 	me->equip(tmp);
// 	ICharacter* bob = new Character("bob");
// 	me->use(0, *bob);
// 	me->use(1, *bob);
// 	delete bob;
// 	delete me;
// 	delete src;