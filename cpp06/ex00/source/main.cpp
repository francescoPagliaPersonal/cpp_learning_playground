#include "ScalarConverter.hpp"
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string.h>

int errorReturn(char *prog, int errNum) {
	std::cout	<< "Error\n"
			<< "Invalid input, "
			<< "conversion cannot be executed.\n\n"
			<< "Example usage:\n"
			<< prog << " c     # to convert a character\n"
			<< prog << " 42    # to convert an integer\n"
			<< prog << " 42.0f # to convert a float\n"
			<< prog << " 42.0  # to convert a double\n\n"
			<< "Please note that for character conversion only a single char is allowed.\n"
			<< std::endl;
	return errNum;
}

void printConv(outData& conv) {

	std::cout << std::fixed << std::setprecision(1) << std::endl;
	if (conv.nbrc_status == OK)
		std::cout << "char   : " << conv.nbrc  << "\n" ;
	else if (conv.nbrc_status == NODISP) 
		std::cout << "char   : " << "Non displayable"  << "\n" ;
	else 
		std::cout << "char   : " << "impossible"  << "\n" ;
	if (conv.nbri_status == OK)
		std::cout << "int    : " << conv.nbri << "\n" ;
	else 
		std::cout << "int    : " << "impossible"  << "\n" ;
	if (conv.nbrf_status == OK)
		std::cout << "float  : " << conv.nbrf << "\n" ;
	else 
		std::cout << "float  : " << "impossible"  << "\n" ;
	if (conv.nbrd_status == OK)
		std::cout << "double : " << conv.nbrd << "\n" ;
	else 
		std::cout << "double : " << "impossible"  << "\n" << std::endl;
}

int main(int ac, char **av)
{
	outData conv;
	memset(&conv, 0, sizeof(conv));
	if (ac != 2) {
		return errorReturn(av[0], 1);
	}

	if (!ScalarConverter::convert(av[1], &conv)) {
		return errorReturn(av[0], 1);
	}
	printConv(conv);
	return (0);

}