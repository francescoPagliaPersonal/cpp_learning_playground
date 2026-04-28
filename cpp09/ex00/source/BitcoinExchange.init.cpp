/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.init.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 09:26:51 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/28 17:56:09 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iomanip>
#include <string>

void BitcoinExchange::init(void) 
{
	std::fstream 	tmp(BITCO_DB, tmp.in);
	std::string 	myline;
	std::string		date;
	std::string		error;
	double			rate;
	
	if (!tmp.is_open())
		throw std::runtime_error("Could not open DataBase file.");
	if (!_checkHeader(tmp, "date,exchange_rate"))
		throw std::runtime_error("Could not resolve header.");
	while (std::getline(tmp, myline))
	{
		if (myline.size() == 0)
			break;
		if (!_parseLine(myline, ",", date, rate, error))	
			throw std::runtime_error(error);
		_dbBTC.insert(std::pair<std::string, double>(date, rate));
		if (DEBUG){
			std::cout	<< std::fixed << std::setprecision(2)
						<< "source  : " << myline << "\n"
						<< "extract : " << date << ":" << rate << std::endl;
		}
	}
}

