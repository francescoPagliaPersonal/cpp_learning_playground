/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalarStruct.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 16:25:17 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/14 16:43:28 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARSTRUCT_H
# define SCALARSTRUCT_H

enum nbrStatus {
	OK,
	ROUND,
	NODISP,
	NOPOSS,
	MAXERR
};

enum inType {
	CHAR,
	INTEGER,
	FLOAT,
	DOUBLE,
	NOTATYPE,
	MAXTYPE	
};

/* This structure is used by the ScalarConverter::convert function
 * to provide with the Scalar version of the number expressed in 
 * the input string.
 * The status of each scalar is notified via the nbrStatus enumerator:
 * - 0: conversion is successful and the data match the source type.
 * - 1: conversion is successful but the data is rounded compared 
 * 		to the source type.
 * - 2: conversion is successful but the value cannot be displayed in 
 * 		the give data type.
 * - 3: conversion not successful value is set to 0.
 */
struct scalars {
	char			nchr;
	nbrStatus		nchr_status;
	int 			nint;
	nbrStatus		nint_status;
	float 			nflo;
	nbrStatus		nflo_status;
	double 			ndou;
	nbrStatus		ndou_status;	
};

#endif
