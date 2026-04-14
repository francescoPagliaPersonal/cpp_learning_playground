/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 16:25:26 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/14 16:43:53 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "scalarStruct.hpp"
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

std::string printMessage(enum nbrStatus stat) {
	if (stat == NOPOSS)
		return "impossible" ;
	if (stat == NODISP)
		return "Non displayable";
	if (stat == ROUND)
		return "\t\t* Rounded";
	return "";
}

void printNumberWithPrecision(double num, enum nbrStatus stat) {
	if (num == std::floor(num))
		std::cout	<< std::fixed 
					<< std::setprecision(1) 
					<< num << std::endl;
	else 
	 	std::cout	<< std::setprecision(6) 
					<< num 
					<< printMessage(stat)
					<< std::endl;
};

void printNumberWithPrecision(float num, enum nbrStatus stat ) {
	if (num == std::floor(num))
		std::cout	<< std::fixed 
					<< std::setprecision(1) 
					<< num << "f" 
					<< printMessage(stat)
					<< std::endl;
	else 
	 	std::cout	<< std::setprecision(10) 
					<< num << std::endl;
};

void printConv(scalars& conv) {

	if (conv.nchr_status <= ROUND)
		std::cout << "char   : " << conv.nchr << printMessage(conv.nchr_status) << std::endl;
	else 
		std::cout << "char   : " << printMessage(conv.nchr_status) << std::endl;
	if (conv.nint_status <= ROUND)
		std::cout << "int    : " << conv.nint << printMessage(conv.nint_status) << std::endl;
	else 
		std::cout << "int    : " << printMessage(conv.nint_status) << std::endl;
	if (conv.nflo_status <= ROUND) {
		std::cout << "float  : " ;	
		printNumberWithPrecision(conv.nflo, conv.nflo_status);
	}
	else if (!(conv.nflo_status == OK))
		std::cout << "float  : " << printMessage(conv.nflo_status) << std::endl;
	if (conv.ndou_status == OK) {
		std::cout << "double : " ;	
		printNumberWithPrecision(conv.ndou, conv.ndou_status);
	}
	else 
		std::cout << "double : " << printMessage(conv.ndou_status) << std::endl;
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
