/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.init.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 09:26:51 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/28 11:50:04 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <cctype>
#include <cstdlib>
#include <cerrno>
#include <memory>
#include <stdexcept>



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
		std::string rate;
		std::getline(tmp, myline);
		if (myline.size() == 0)
			break;
		date = _extractDate(myline);
		if (date.size() == 0)
			throw std::runtime_error("Invalid entry - wrong date format.");
		
		std::string pattern(",");
		std::string delimiter = myline.substr(DATE_LEN, pattern.size());
		if (delimiter != pattern)
			throw std::runtime_error("Invalid entry - wrong delimiter.");
		
		
		rate = myline.substr(DATE_LEN + pattern.size(), myline.size());

		char *end;
		errno = 0;
		double number = std::strtod(rate.c_str(), &end);
		if (errno != 0)
			throw std::runtime_error("Invalid entry - wrong value format.");
		if (*end != 0)
		{
			std::cout << "value of end: '" << *end << "'" <<std::endl;
			while (*end != 0)
			{
				if (!std::isspace(*end))
					throw std::runtime_error("Invalid entry - unexpected character in entry.");
				++end;
			}
		}
		_dbBTC.insert(std::pair<std::string, double>(date, number));
		
	}
	std::map<std::string, double>::const_iterator mapIt = _dbBTC.begin();
	for (; mapIt != _dbBTC.end(); ++mapIt)
		std::cout << mapIt->first << "::" << mapIt->second << std::endl;
	std::cout << "items in map: "<< _dbBTC.size() << std::endl;
}
