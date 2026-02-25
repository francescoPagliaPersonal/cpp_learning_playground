
#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main(void)
{
	Animal*	zoo[50];
	Brain	mind;
	
	for (int i = 0; i < 50; ++i)
	{	
		if (i % 2 == 0)
			zoo[i] = new Dog();
		else 
			zoo[i] = new Cat();
	}
	for (int i = 0; i < 50; ++i)
		delete zoo[i];

	std::cout << "Hello" << std::endl;
	Animal*	jeff = new Cat();
	/* the following is not the best approach a clone() virtual function should be
	 * added to the base class. so to have a fully polymorphism approach to 
	 * actually create any Animal (in our case)
	 */
	
	Animal* john = new Cat(*(static_cast<Cat*>(jeff))); 
	std::cout << "Jeff thought: " << jeff->getIdea(5) << "\n";
	jeff->changeIdea(5,"Hello World");
	std:: cout << "Jeff changed his mind: " << jeff->getIdea(5) << "\n"
			<< "while John was firm on the first idea: " << john->getIdea(5)
			<< std::endl;
}