/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 15:00:15 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/14 13:19:01 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cctype>
#include <cmath>
#include <cstring>
#include <limits>

inData ScalarConverter::_input;

bool ScalarConverter::convert(const char *str, scalars *conv)
{
	std::memset(conv, 0, sizeof(*conv));
	int status = 0;
	if (!validateInput(str))
		return false;
	
	switch (_input.type) {
		case 0:
			status = convertChar(conv);
			break ;
		case 1:
			status = convertInt(conv);
			break ;
		case 2:
			status = convertFloat(conv);
			break ;
		case 3:
			status = convertDouble(conv);
			break ;
		default:
			status = convertNone(conv);
			break;
	}
	return status;
}

void ScalarConverter::setError(scalars *conv)
{
	conv->nbrc_status = NOPOSS;
	conv->nbri_status = NOPOSS;
	conv->nbrf_status = NOPOSS;
	conv->nbrd_status = NOPOSS;
}

bool ScalarConverter::fitsInteger(long num) {
	return (num <= std::numeric_limits<int>::max()
		&& num >= std::numeric_limits<int>::min());
}

bool ScalarConverter::fitsFloat(double num) {
	return (num <= std::numeric_limits<float>::max()
		&& num >= -std::numeric_limits<float>::max());
}

void ScalarConverter::intToChar(int num, scalars *conv) {
	conv->nbrc = static_cast<unsigned char>(num);
	if (num > std::numeric_limits<unsigned char>::max() || num < 0) 
		conv->nbrc_status = NOPOSS;
	else if (std::isprint(num))
		conv->nbrc_status = OK;
	else conv->nbrc_status = NODISP;
}


bool ScalarConverter::convertNone(scalars *conv) {
	(void) conv;
	return true;
}

bool ScalarConverter::convertLitteral(scalars *conv, double num) {
	
	conv->nbrc_status = NOPOSS;
	conv->nbri_status = NOPOSS;
	
	conv->nbrf = static_cast<float>(num);
	conv->nbrf_status = OK;

	conv->nbrd = num;
	conv->nbrd_status = OK;
	
	return true;
}