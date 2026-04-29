/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 12:18:19 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/29 09:30:44 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#define ERR_INPUT "Error: wrong number of parameter.\nTo run correctly please use:\n \
btc {input file with \"date | value\" pairs}"

#include "BitcoinExchange.hpp"
#include <iostream>

int main(int ac, char** av) {

	if (ac != 2) {
		std::cout << ERR_INPUT << std::endl;
		return 1;
	}
	try {BitcoinExchange::init();}
	catch (std::exception& e)
		{ std::cerr << "ERROR: "<< e.what() << std::endl;	}
	try {BitcoinExchange::convert(av[1]);}
	catch (std::exception& e)
		{ std::cerr << "ERROR: "<< e.what() << std::endl;	}
	return 0;
}
