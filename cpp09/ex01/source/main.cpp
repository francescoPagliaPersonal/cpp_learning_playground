/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 10:00:14 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/29 12:54:00 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <exception>
#include <iostream>

int main(int ac, char **av)
{
	if (ac != 2) {
		std::cout << "Error: add a single calculation in a string.\n" 
					<< "in example \"5 6 + 7 -\""<< std::endl;
		return 1;
	}
	try 
	{ 
		int calculation = RPN::result(av[1]);
		std::cout << calculation << std::endl; 
	}
	catch (std::exception & e) {
		std::cout << "Error: " << e.what() << std::endl;
		return 1;
	};
	return 0;
}
