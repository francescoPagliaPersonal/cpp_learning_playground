/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.convert.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 17:57:07 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/28 18:38:41 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iomanip>

bool _validateRate(const double & number, std::string & error) {
	if (number < 0) {
		error = "not a positive number.";
		return false;
	}
	if (number > 1000) {
		error = "too large of a number";
		return false;
	}
	return true;
}

void BitcoinExchange::convert(const char* file) {

	std::fstream 	tmp(file, tmp.in);
	std::string 	myline;
	std::string		date;
	std::string		error;
	double			rate;
	
	if (!tmp.is_open())
		throw std::runtime_error("Could not open input file.");
	if (!_checkHeader(tmp, "date | value"))
		throw std::runtime_error("Could not resolve header.");
	while (std::getline(tmp, myline))
	{
		if (myline.size() == 0) {
			std::cout << "Error: empty line" << std::endl;
			continue;
		}
		if (!_parseLine(myline, " | ", date, rate, error))	{
			std::cout << "Error: bad input : " << error << " => " << myline << std::endl;
			continue;
		}
		if (!_validateRate(rate, error)) {
			std::cout << "Error: " << error << std::endl; 
			continue;
		}
		std::map<std::string, double>::iterator it = _dbBTC.find(date);
		if (it == _dbBTC.end()) {
			it = _dbBTC.lower_bound(date);
			--it;
		}
		std::cout << it->first << " => " << rate << " = " << it->second * rate << std::endl;
		
	}
}