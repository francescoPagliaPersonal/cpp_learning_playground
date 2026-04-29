/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 14:34:15 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/29 15:40:19 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <exception>
#include <iostream>

int main(int ac, const char **av)
{
	if (ac < 3) {
		std::cerr << "Error: Not enough arguments." << std::endl;
		return 1;
	}
	
	PmergeMe	array;
	try {
		array.ingest(&av[1]);
		array.print();
		
	}
	catch (std::exception & e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return 0;
}
