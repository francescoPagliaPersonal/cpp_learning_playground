/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 15:00:15 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/10 18:32:17 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cctype>

bool ScalarConverter::convert(const char *str)
{
	if (!validateInput(str))
		return false;
	if (!strToData(input)) {
		setOutput();
		return false;
	}
	switch (input.type) {
		case 0:
			setOutput(convertions.nbrc);
			break ;
		case 1:
			setOutput(convertions.nbri);
			break ;
		case 2:
			setOutput(convertions.nbrf);
			break ;
		case 3:
			setOutput(convertions.nbrd);
			break ;
		default:			
			break;
	}
	return true;
}

bool ScalarConverter::validateInput(const char* str) {
	std::string tmp(str);
	{
		std::string::size_type start = tmp.find_first_not_of(" \t\n\r");
		if (start == std::string::npos)
			return input.status = ERRMAX, false;
		std::string::size_type end = tmp.find_last_not_of(" \t\n\r");
		tmp.substr(start, end - start + 1);
	}
	if (checkLitterals(tmp))
		return true;
	int sign = 0;
	int dot = 0;
	int char_f = 0;
	// while (std::string::)
	// TODO execute the checks to get to the final type
	// if wrong character is encountered return false
	return true;
}




/*
check if the are more than 2 inputs 
	if yes return error,
clean up trailing an leading spaces 
verify if there is any space left inbetween
if yes return error

check litteral cases:
inf
inff
+inf
+inff
-inf
-inff
nan
nanf

check if starts with a sign 
	if it's signed and the next char is not a number return "error"
	
check if the next char is a number
	if not and is signed return "error"
	if not and is not signed and there is +1 char return "error"
		else return the char and convert all the other types
	if yes:
	check if the rest of the string is number only
		if yes mark it as INT 
		if it's not the first interruption is a . walk again till you have EOL or f
			if it's EOL mark it as DOUBLE
			else if its f and next char is EOL mark it as FLOAT
			else  return "error"
	if all the test have passed run strtod if an overflow error appear return "error"
	if not check the Type recorded and check against the type recorded if the value overflows the given type.
		if so return "error" 
	
	to render the text, check the data type and implent conversions based on this info

*/
