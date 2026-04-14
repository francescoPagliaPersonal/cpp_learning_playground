#include "ScalarConverter.hpp"
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ios>
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

void print0(double num) {
	if (num == std::floor(num))
		std::cout	<< std::fixed 
					<< std::setprecision(1) 
					<< num << std::endl;
	else 
	 	std::cout	<< std::setprecision(10) 
					<< num << std::endl;
};

void print0(float num) {
	if (num == std::floor(num))
		std::cout	<< std::fixed 
					<< std::setprecision(1) 
					<< num << "f" << std::endl;
	else 
	 	std::cout	<< std::setprecision(10) 
					<< num << std::endl;
};


void printConv(scalars& conv) {

	// std::cout << std::fixed << std::showpoint << std::endl;
	if (conv.nbrc_status == OK)
		std::cout << "char   : " << conv.nbrc  << std::endl;
	else if (conv.nbrc_status == NODISP) 
		std::cout << "char   : " << "Non displayable"  << std::endl;
	else 
		std::cout << "char   : " << "impossible"  << std::endl;
	if (conv.nbri_status == OK)
		std::cout << "int    : " << conv.nbri << std::endl;
	else 
		std::cout << "int    : " << "impossible"  << std::endl;
	if (conv.nbrf_status == OK) {
		std::cout << "float  : " ;	print0(conv.nbrf);
	}
	else 
		std::cout << "float  : " << "impossible"  << std::endl;
	if (conv.nbrd_status == OK) {
		std::cout << "double : " ;	print0(conv.nbrd);
	}
	else 
		std::cout << "double : " << "impossible"  << std::endl;
}

int main(int ac, char **av)
{
	scalars conv;
	
	if (ac != 2) {
		return errorReturn(av[0], 1);
	}

	if (!ScalarConverter::convert(av[1], &conv)) {
		return errorReturn(av[0], 1);
	}
	printConv(conv);
	return (0);

}