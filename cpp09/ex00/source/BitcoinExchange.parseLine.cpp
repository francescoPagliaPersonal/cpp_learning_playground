/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.parseLine.cpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 14:48:03 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/28 16:26:39 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool BitcoinExchange::_parseLine(
	const std::string & line, 
	const std::string & delimiter,
		std::string & date,
		double      & rate,
		std::string & error)
{
	std::string::size_type pos = line.find(delimiter);
	if (pos == line.npos) {
		error = "Invalid entry - missing delimiter.";
		return false;
	}
	date = line.substr(0, pos);
	if (!_isvalidDate(date)) {
		error = "Invalid entry - wrong date format.";
		return false;
	}
	std::string value = line.substr(pos + delimiter.size());
	if (!_extractRate(value, rate, error)) 
		return false;
	
	return true;
}
