
#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

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

	Cat	jeff;
	Cat	john(jeff);
	
}