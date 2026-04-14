/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.int.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 16:26:19 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/14 16:26:21 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <errno.h>
#include <cstdlib>


bool ScalarConverter::convertInt(scalars *conv) {
	const char *str = _in_str.c_str();
	char *end;
	errno = 0;
	long num = std::strtol(str, &end, 10);
	if (errno != 0)	{
		setError(conv);
		return false;
	}
	
	if (!fitsInteger(num)){
		setError(conv);
		return false;
	}
	
	conv->nint = num;
	conv->nint_status = OK;
	intToChar(num, conv);
	conv->nflo = static_cast<float>(num);
	if (num == static_cast<int>(conv->nflo))
		conv->nflo_status = OK;
	else
	 	conv->nflo_status = NOPOSS;
	conv->ndou = static_cast<double>(num);
	if (num == static_cast<int>(conv->ndou))
		conv->ndou_status = OK;
	else
	 	conv->ndou_status = NOPOSS;
	return true;		
}
