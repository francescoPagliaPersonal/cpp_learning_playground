#include "ScalarConverter.hpp"
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string.h>

int main(int ac, char **av)
{
	outData conv;
	memset(&conv, 0, sizeof(conv));
	if (ac != 2) {
		std::cout	<< "Error\n"
					<< "Invalid input, "
					<< "conversion cannot be executed.\n\n"
					<< "Example usage:\n"
					<< av[0] << " c     # to convert a character\n"
					<< av[0] << " 42    # to convert an integer\n"
					<< av[0] << " 42.0f # to convert a float\n"
					<< av[0] << " 42.0  # to convert a double\n\n"
					<< "Please note that for character conversion only a single char is allowed.\n"
					<< std::endl;
		return 1;
	}

	if (ScalarConverter::convert(av[1], &conv)) {
		
		std::cout << std::fixed << std::setprecision(1)
				  << "char   : " << conv.nbrc  << "\n"   
				  << "int    : " << conv.nbri << "\n"
				  << "float  : " << conv.nbrf << "f\n" 
				  << "double : " << conv.nbrd << "\n" << std::endl;

	}

}