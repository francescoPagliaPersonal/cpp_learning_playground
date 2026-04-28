/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.init.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 09:26:51 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/28 15:18:31 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <cctype>
#include <cstdlib>
#include <cerrno>
// #include <stdexcept>

bool BitcoinExchange::_followsValidDelimiter(const std::string & source, const std::string & pattern)
{
	std::string delimiter = source.substr(DATE_LEN, pattern.size());
	return delimiter == pattern ? true : false;
}

double BitcoinExchange::_extractRate(const std::string & source, int offset) 
{
	std::string value = source.substr(offset, source.size());
	
	char *end;
	errno = 0;
	double number = std::strtod(value.c_str(), &end);
	if (value.c_str() == end)
		return (errno = ERANGE, -1.0);
	if (errno == ERANGE)
		return -1.0;
	if (*end != 0)
	{
		std::cout << "value of end: '" << *end << "'" <<std::endl;
		while (*end != 0)
		{
			if (!std::isspace(*end))
				return (errno = EINVAL, -1.0);
			++end;
		}
	}
	return number;
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
		double		rate;
		std::string delimiter(",");
		
		std::getline(tmp, myline);
		if (myline.size() == 0)
			break;
		
		date = _extractDate(myline);
		if (date.size() == 0)
			throw std::runtime_error("Invalid entry - wrong date format.");
		
		if (!_followsValidDelimiter(myline, ","))
			throw std::runtime_error("Invalid entry - wrong delimiter.");
				
		
		rate = _extractRate(myline, DATE_LEN + delimiter.size());
		if (errno == ERANGE)
			throw std::runtime_error("Invalid entry - wrong value format.");
		if (errno == EINVAL)
			throw std::runtime_error("Invalid entry - unexpected character in entry.");
		
		_dbBTC.insert(std::pair<std::string, double>(date, rate));
		
	}
	std::map<std::string, double>::const_iterator mapIt = _dbBTC.begin();
	for (; mapIt != _dbBTC.end(); ++mapIt)
		std::cout << mapIt->first << "::" << mapIt->second << std::endl;
	std::cout << "items in map: "<< _dbBTC.size() << std::endl;
}

/*
std::string date;
double rate;
std::string err;
if (!parseLine(line, ",", date, rate, err))
    throw std::runtime_error(err);
*/