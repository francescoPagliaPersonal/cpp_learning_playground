/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.float.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 16:25:39 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/14 16:25:40 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <errno.h>
#include <cstdlib>


bool ScalarConverter::convertFloat(scalars *conv) {
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
	if (!fitsFloat(num)){
		setError(conv);
		return false;
	}
	conv->nflo = static_cast<float>(num);
	conv->nflo_status = OK;
		
	conv->ndou = static_cast<double>(conv->nflo);
	conv->nflo == static_cast<float>(conv->ndou)
		? conv->ndou_status = OK
		: conv->ndou_status = ROUND;
	
	if (!fitsInteger(static_cast<long>(conv->nflo)))
		conv->nint_status = NOPOSS;
	else {
		conv->nint = static_cast<int>(conv->nflo);
		conv->nflo ==  static_cast<int>(conv->nint) 
			? conv->nint_status = OK 
			: conv->nint_status = ROUND; 
	} 
	if (conv->nint_status <= ROUND )
		intToChar(conv->nint, conv);
	else
		(conv->nchr_status = NOPOSS);
	return true;
}
