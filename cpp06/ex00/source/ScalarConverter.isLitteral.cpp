/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.isLitteral.cpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 16:25:46 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/14 16:25:47 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

std::string ScalarConverter::_litteralNumbers[LITTERALNUMBER] = {
	"inff",
	"+inff",
	"-inff",
	"nanf",
	"inf",
	"+inf",
	"-inf",
	"nan"
};

bool ScalarConverter::isLitterals(std::string str) {
	
	for (std::string::iterator it = str.begin(); it != str.end(); ++it ) 
		*it = std::tolower(static_cast<unsigned char>(*it));
	
	int i = 0;
	while (i < LITTERALNUMBER)
	{
		if (_litteralNumbers[i] == str)
			break ;
		++i;
	}
	if (i < LITTERALNUMBER / 2)
		_in_type = FLOAT;
	else if (i < LITTERALNUMBER)
		_in_type = DOUBLE;
	_in_litteral = i < LITTERALNUMBER;
	return (_in_litteral);
}
