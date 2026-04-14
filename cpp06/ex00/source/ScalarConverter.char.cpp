/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.char.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 16:25:59 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/14 16:26:05 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"


bool ScalarConverter::convertChar(scalars *conv) {
	conv->nchr = _in_str.c_str()[0];
	conv->nchr_status = OK;
	conv->nint = static_cast<int>(conv->nchr);
	conv->nint_status = OK;
	conv->ndou = static_cast<double>(conv->nint);
	conv->ndou_status = OK;
	conv->nflo = static_cast<float>(conv->ndou);
	conv->nflo_status = OK;
	return true;
}
