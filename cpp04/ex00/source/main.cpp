
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

	std::cout << j->getType() << " << Animal* j " << std::endl;
	std::cout << i->getType() << " << Animal* i  " << std::endl;
	std::cout << k->getType() << " << Animal* k " << std::endl;
	std::cout << u.getType() << " << Animal* u " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	k->makeSound();
	meta->makeSound();
	u.makeSound();

	delete meta;
	delete i;
	delete j;
	delete k;
	return 0;
}