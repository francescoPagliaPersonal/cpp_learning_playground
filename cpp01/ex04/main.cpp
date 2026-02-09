#include "Looser.class.hpp"
#include <iostream>
#include <ostream>

int main(int ac, char **av)
{
	std::cout << "items: " << ac << std::endl;
	if (ac != 4)
		return 1;
	Looser myaction(av[1], av[2], av[3]);

	myaction.replace();
	return 0;
}