/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 13:53:40 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/27 18:18:11 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <cctype>
#include <fstream>
#include <iostream>
#include <istream>
#include <sstream>
#include <stdexcept>

std::map<std::string, double> 	BitcoinExchange::_dbBTC;

inline bool		BitcoinExchange::_checkHeader(std::fstream & in, const std::string & title) {
	std::string myline;
	std::getline(in, myline);
	return myline == title;
}

inline std::string	BitcoinExchange::_extractDate(const std::string & date) {
	std::string extractedDate("");
	std::string::const_iterator it = date.begin();
	for (int i = 0; i < 10; ++i) {
		if ((i == 4 || i == 7) && (*(it + i) != '-' ))
			return std::string("");
		else if (i != 4 && i != 7 && !std::isdigit( *(it + i) ))
			return std::string("");
	}
	extractedDate = date.substr(0, 10);
	return extractedDate;
}

void BitcoinExchange::init(void) 
{
	std::fstream 	tmp(BITCO_DB, tmp.in);
	
	if (!tmp.is_open())
		throw std::runtime_error("Could not open DataBase file.");
	if (!_checkHeader(tmp, "date,exchange_rate"))
		throw std::runtime_error("Could not resolve header.");
	while (!tmp.eof())
	{
		std::string myline;
		std::string date;
		std::getline(tmp, myline);
		if (myline.size() == 0)
			break;
		date = _extractDate(myline);
		if (date.size() == 0)
			throw std::runtime_error("Invalid entry - wrong date format.");
		std::string pattern(",");
		std::string delimiter = myline.substr(DATE_LEN, DATE_LEN + pattern.size());
		if (delimiter != pattern)
			throw std::runtime_error("Invalid entry - wrong delimiter.");

		// TODO: add the conversion of the number and throw if after the end there is more than just empty space.
		// then extract all in proper function

		char *end;
		double number = std::strtod(myline.c_str() + DATE_LEN + pattern.size(), &end);
		_dbBTC.insert(std::pair<std::string, double>(date, number));
		
	}
	std::map<std::string, double>::const_iterator mapIt = _dbBTC.begin();
	for (; mapIt != _dbBTC.end(); ++mapIt)
		std::cout << mapIt->first << "::" << mapIt->second << std::endl;
	std::cout << "items in map: "<< _dbBTC.size() << std::endl;
}


void BitcoinExchange::convert(const char* file) {
	(void)file;
	return ;	
}