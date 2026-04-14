/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.litteral.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 16:26:26 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/14 16:26:32 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool ScalarConverter::convertLitteral(scalars *conv, double num) {
	
	conv->nchr_status = NOPOSS;
	conv->nint_status = NOPOSS;
	
	conv->nflo = static_cast<float>(num);
	conv->nflo_status = OK;

	conv->ndou = num;
	conv->ndou_status = OK;
	
	return true;
}
