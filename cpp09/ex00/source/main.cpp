/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 12:18:19 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/27 12:42:19 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#define ERR_INPUT "Error\nwrong number of parameter.\nTo run correctly please use:\n \
btc {input file with \"date | value\" pairs}"

#include "BitcoinExchange.hpp"
#include <iostream>

int main(int ac, char** av) {

	if (ac != 2) {
		std::cout << ERR_INPUT << std::endl;
		return 1;
	}
	try {BitcoinExchange::convert(av[1]);}
	catch (std::exception& e)
		{ std::cerr << "ERROR: "<< e.what() << std::endl;	}
	// open the file in av
	// for each line output the expected result to the terminal
	return 0;
}
