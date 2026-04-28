/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.extractDate.cpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 11:44:09 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/28 15:36:56 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <cerrno>


static bool isLeapYear(int year)
{
    return (year % 400 == 0) ||
           (year % 4 == 0 && year % 100 != 0);
}

static int daysInMonth(int month, int year)
{
    switch (month)
    {
        case 1: case 3: case 5: case 7:
        case 8: case 10: case 12:
            return 31;

        case 4: case 6: case 9: case 11:
            return 30;

        case 2:
            return isLeapYear(year) ? 29 : 28;

        default:
            return 0; 
    }
}

bool	BitcoinExchange::_isvalidDate(const std::string & date)
{
	if (date.size() != DATE_LEN) 
		return false;
	
	const char	*start = date.c_str();
	char		*end;
	int			dateitem[3];
	
	for (int i = 0; i < 3; ++i)
	{
		errno = 0;
		dateitem[i] = std::strtol(start, &end, 10);
		if (errno != 0)
			return false;
		if (i < 2) 
		{
			if (*end != '-')
				return false;
			start = end + 1;
		} 
	}
	if (end - date.c_str() != DATE_LEN)
		return false;
	if (dateitem[0] < 2000)
		return false;
	if (!(dateitem[1] > 0 && dateitem[1] <= 12))
		return false;
	if (!(dateitem[2] > 0 && dateitem[2] <= daysInMonth(dateitem[1], dateitem[0])))
		return false;
	return true;
}
