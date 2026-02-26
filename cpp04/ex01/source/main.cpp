
#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

# define ANIM_COUNT 20

int main(void)
{
	unsigned int	ideaID = 1;
	Animal*			zoo[ANIM_COUNT];
	
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
		std::cout << "\n -----------START OF ZOO DESTRUCTOR--------------- \n" << std::endl;

	for (int i = 0; i < ANIM_COUNT; ++i)
		delete zoo[i];

	if (DEBUG == 0)
		std::cout << "\n -----------END OF ZOO DESTRUCTOR--------------- \n" << std::endl;

	Cat jeff;
	Cat john(jeff);
	if (DEBUG == 0)
		std::cout << "\n -----------END OF SPARSE CATS CONSTRUCTORS--------------- \n" << std::endl;
	
	std::cout << "Jeff thought: " << jeff.getIdea(ideaID) << "\n";
	jeff.changeIdea(ideaID,"Hello World");
	std:: cout << "Jeff changed his mind: " << jeff.getIdea(ideaID) << "\n"
			<< "while John was firm on the first idea: " << john.getIdea(5)
			<< std::endl;

	if (DEBUG == 0)
		std::cout << "\n -----------START OF SPARSE CATS DESTRUCTOR--------------- \n" << std::endl;

}