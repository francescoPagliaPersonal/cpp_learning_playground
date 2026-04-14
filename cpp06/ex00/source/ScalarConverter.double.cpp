/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.double.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 16:26:11 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/14 16:26:13 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <errno.h>
#include <cstdlib>


bool ScalarConverter::convertDouble(scalars *conv) {
	const char *str = _in_str.c_str();
	char *end;
	errno = 0;
	double num = std::strtod(str, &end);
	if (errno != 0)	{
		setError(conv);
		return false;
	}

	if (_in_litteral) {
		convertLitteral(conv, num);
		return true;
	}
	
	conv->ndou = num;
	conv->ndou_status = OK;
	
	if (!fitsFloat(num)){
		conv->nflo_status = NOPOSS;
	}
	else {
		conv->nflo = static_cast<float>(num);
		conv->ndou == static_cast<double>(conv->nflo)
			? conv->nflo_status = OK
		 	: conv->nflo_status = ROUND;
	}
	if (!fitsInteger(static_cast<long>(conv->ndou)))
		conv->nint_status = NOPOSS;
	else {
		conv->nint = static_cast<int>(conv->ndou);
		num ==  static_cast<int>(conv->nint) 
			? conv->nint_status = OK 
			: conv->nint_status = ROUND; 
	} 
	if (conv->nint_status == OK )
		intToChar(conv->nint, conv);
	else
		(conv->nchr_status = NOPOSS);
	return true;
}
