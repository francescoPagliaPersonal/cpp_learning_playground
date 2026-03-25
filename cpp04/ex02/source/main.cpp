/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 17:14:22 by fpaglia           #+#    #+#             */
/*   Updated: 2026/03/24 17:14:24 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "AAnimal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>
#include <ostream>

# define ANIM_COUNT 20

int main(void)
{
	unsigned int		ideaID = 5;
	AAnimal*			zoo[ANIM_COUNT];

	if (DEBUG == 0)
		std::cout << "\n -----------START OF ZOO CONSTRUCTORS--------------- \n" << std::endl;
	for (int i = 0; i < ANIM_COUNT; ++i)
	{	
		if (i % 2 == 0)
			zoo[i] = new Dog();
		else 
			zoo[i] = new Cat();
	}

	if (DEBUG == 0)
		std::cout << "\n -----------SHOWING OFF IDEAS----------------------- \n" << std::endl;
	
	std::cout << "the animal id 0 is a: " << zoo[0]->getType() << "\t"
			<< "it thought: " << zoo[0]->getIdea(ideaID) 
			<< " but then changed to: ";
	zoo[0]->changeIdea(ideaID,"I'd like to have better ideas");
	std::cout << zoo[0]->getIdea(ideaID) << "\n"
			<< "the animal id 1 is a: " << zoo[1]->getType() << "\t"
			<< "it thought: " << zoo[1]->getIdea(ideaID) 
			<< " but then changed to: ";
	zoo[1]->changeIdea(ideaID,"I'm tired of thinking");
	std::cout << zoo[1]->getIdea(ideaID) << "\n" << "\n"
			<< "what was the first animal thinking? " << zoo[0]->getIdea(ideaID) << "\n"
			<< "which are all the other ideas?" << std::endl;
	for (int i = 0; i < MAX_STRINGS + 1; ++i)
		std::cout << zoo[1]->getIdea(i) << std::endl;

	if (DEBUG == 0)
		std::cout << "\n -----------START OF ZOO DESTRUCTOR--------------- \n" << std::endl;

	for (int i = 0; i < ANIM_COUNT; ++i)
	{
		zoo[i]->makeSound();
		delete zoo[i];
	}

	if (DEBUG == 0)
		std::cout << "\n -----------END OF ZOO DESTRUCTOR--------------- \n" << std::endl;
	
	AAnimal*	jeff = new Cat();
	AAnimal*	john = jeff->clone(); 

	if (DEBUG == 0)
		std::cout << "\n -----------END OF SPARSE CATS CONSTRUCTORS--------------- \n" << std::endl;
	

	std::cout << "Jeff thought: " << jeff->getIdea(ideaID) << "\n";
	jeff->changeIdea(ideaID,"Hello World");
	std:: cout << "Jeff changed his mind: " << jeff->getIdea(ideaID) << "\n"
			<< "while John was firm on the first idea: " << john->getIdea(5)
			<< std::endl;

	if (DEBUG == 0)
		std::cout << "\n -----------START OF SPARSE CATS DESTRUCTOR--------------- \n" << std::endl;

	delete jeff;
	delete john;
}
