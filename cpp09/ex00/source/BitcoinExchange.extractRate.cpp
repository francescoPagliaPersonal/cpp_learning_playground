/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.extractRate.cpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 15:59:40 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/28 16:23:30 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "BitcoinExchange.hpp"
#include <cerrno>

bool BitcoinExchange::_extractRate(
	const std::string	& value,
		  double 		& number,
		  std::string 	& error) 
{
	char *end;
	errno = 0;
	number = std::strtod(value.c_str(), &end);
	if (value.c_str() == end) {
		error = "missing rate.";
		return false;
	}
	
	if (errno == ERANGE) {
		error = "rate value out of range.";
		return false;
	}
	if (*end != 0)
	{
		while (*end != 0)
		{
			if (!std::isspace(static_cast<unsigned char>(*end))) {
				error = "wrong rate format.";
				return false;
			}
			++end;
		}
	}
	return true;
}


