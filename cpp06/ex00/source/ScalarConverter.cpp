/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 15:00:15 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/14 16:10:40 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "scalarStruct.hpp"
#include <cctype>
#include <cmath>
#include <cstring>
#include <limits>

std::string	ScalarConverter::_in_str;
inType		ScalarConverter::_in_type;
int 		ScalarConverter::_in_litteral = 0;

bool ScalarConverter::convert(const char *str, scalars *conv)
{
	std::memset(conv, 0, sizeof(*conv));
	int status = 0;
	if (!validateInput(str))
		return false;
	
	switch (_in_type) {
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
	conv->nchr_status = NOPOSS;
	conv->nint_status = NOPOSS;
	conv->nflo_status = NOPOSS;
	conv->ndou_status = NOPOSS;
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
	conv->nchr = static_cast<unsigned char>(num);
	if (num > std::numeric_limits<unsigned char>::max() || num < 0) 
		conv->nchr_status = NOPOSS;
	else if (std::isprint(num))
		conv->nchr_status = conv->nint_status;
	else conv->nchr_status = NODISP;
}


