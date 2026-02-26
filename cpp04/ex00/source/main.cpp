
#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* k = new WrongCat();
	const WrongAnimal u("Paguro");

	std::cout << "\n -----------ADDITIONAL CONSTRUCTORS--------------- \n" << std::endl;
	Dog	Juri;
	Juri.makeSound();
	Dog	Missy(Juri);
	Missy.makeSound();
	Dog	Nancy;
	Nancy = Missy;
	Nancy.makeSound();
	std::cout << "\n" << std::endl;
	Cat	Juli;
	Juli.makeSound();
	Cat	Nizzi(Juli);
	Nizzi.makeSound();
	Cat	Brilli;
	Brilli = Nizzi;
	Brilli.makeSound();

	std::cout << "\n -----------END OF CONSTRUCTORS--------------- \n" << std::endl;
	std::cout << "Animal* meta: " << meta->getType()  << std::endl;
	meta->makeSound();
	std::cout << " -------------------------- " << std::endl;
	std::cout << "Animal* j:    " << j->getType()  << std::endl;
	j->makeSound();
	std::cout << " -------------------------- " << std::endl;
	std::cout << "Animal* i:    " << i->getType()  << std::endl;
	i->makeSound(); //will output the cat sound!
	std::cout << " -------------------------- " << std::endl;
	std::cout << "Animal* k:    " << k->getType()  << std::endl;
	k->makeSound();
	std::cout << " -------------------------- " << std::endl;
	std::cout << "Animal* u:    " << u.getType()  << std::endl;
	u.makeSound();
	std::cout << "\n -----------START OF DESTUCTOR--------------- \n" << std::endl;

	delete meta;
	delete i;
	delete j;
	delete k;
	return 0;
}