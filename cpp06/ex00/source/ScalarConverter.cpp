/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 15:00:15 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/13 14:43:49 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <limits>
#include <errno.h>


std::string ScalarConverter::_littNum[LITTERALNUMBER] = {
	"inff",
	"+inff",
	"-inff",
	"nanf",
	"inf",
	"+inf",
	"-inf",
	"nan"
};

inData ScalarConverter::_input;

bool ScalarConverter::convert(const char *str, outData *conv)
{
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

bool ScalarConverter::checkLitterals(std::string str) {
	
	for (std::string::iterator it = str.begin(); it != str.end(); ++it ) 
		*it = std::tolower(static_cast<unsigned char>(*it));
	
	int i = 0;
	while (i < LITTERALNUMBER)
	{
		if (_littNum[i] == str)
			break ;
		++i;
	}
	if (i < LITTERALNUMBER / 2)
		_input.type = FLOAT;
	else if (i < LITTERALNUMBER)
		_input.type = DOUBLE;
	return (i < LITTERALNUMBER);
}



/* Given a string validate if the input is properly formatted.
 * Check if it is a litteral non numerical value
 * Starts with a +/- sign (optional)
 * Has an interrupted series of numbers.
 * Has at most one dot "." (optional)
 * Ends with "f" (optional)
 *
 * Returns
 * Fill up the "input" inData structure 
 */
bool ScalarConverter::validateInput(const char* str) {
	
	_input.sign = 0;
	_input.type = NOTATYPE;
	_input.str.assign(str);
	
	std::string& tmp = _input.str;
	std::string::iterator it = tmp.begin();
	
	if (!std::isdigit(static_cast<unsigned char>(*it))
		&& (std::isprint(static_cast<unsigned char>(*it)) 
		&& (it + 1 == tmp.end()))) {
		_input.type = CHAR;
		return true;
	}

	if (checkLitterals(tmp))
		return true;
	
	if (*it == '+' || *it == '-'){
		*it == '+' ? _input.sign =	1 : _input.sign = -1;
		++it;
	}
	
	int dot = 0;
	int char_f = 0;
	while (it != tmp.end())
	{
		if (!std::isdigit(static_cast<unsigned char>(*it)))
			break;
		++it;
	}
	if (it != tmp.end()) {
		if (*it == '.')
			dot = 1;
		else if (static_cast<unsigned char>(*it) == 'f')
			char_f = 1;
		else 
			return false;
		++it;
	}
	if (dot == 1) {
		if (!std::isdigit(static_cast<unsigned char>(*it)))
			return false;
		else {
			while (it != tmp.end())
			{
				if (!std::isdigit(static_cast<unsigned char>(*it)))
					break;
				++it;
			}
		}
		if (*it == 'f') {
			char_f = 1;
			++it;	
		}
	}
	if (it != tmp.end())
		return false;
	
	dot == 1 ? _input.type = DOUBLE : _input.type = INTEGER;
	char_f == 1 ? _input.type = FLOAT : _input.type = _input.type;
	return true;
}

bool ScalarConverter::convertChar(outData *conv) {
	conv->nbrc = _input.str.c_str()[0];
	conv->nbrc_status = OK;
	conv->nbri = conv->nbrc - '0';
	conv->nbri_status = OK;
	conv->nbrd = static_cast<double>(conv->nbri);
	conv->nbrd_status = OK;
	conv->nbrf = static_cast<float>(conv->nbrd);
	conv->nbrf_status = OK;
	return true;
}
void setError(outData *conv)
{
	conv->nbrc_status = NOPOSS;
	conv->nbri_status = NOPOSS;
	conv->nbrf_status = NOPOSS;
	conv->nbrd_status = NOPOSS;
}

bool fitsInteger(long num) {
	return (num < std::numeric_limits<int>::max()
		&& num > std::numeric_limits<int>::min());
}

bool fitsFloat(double num) {
	return (num < std::numeric_limits<float>::max()
		&& num > -std::numeric_limits<float>::max());
}

void intToChar(int num, outData *conv) {
	conv->nbrc = static_cast<unsigned char>(num);
	if (std::isprint(num))
		conv->nbrc_status = OK;
	else if (num > std::numeric_limits<unsigned char>::max() || num < 0) 
		conv->nbrc_status = NOPOSS;
	else conv->nbrc_status = NODISP;
}

bool ScalarConverter::convertInt(outData *conv) {
	const char *str = _input.str.c_str();
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
	
	conv->nbri = num;
	conv->nbri_status = OK;
	intToChar(num, conv);
	conv->nbrf = static_cast<float>(num);
	if (num == conv->nbrf)
		conv->nbrf_status = OK;
	else
	 	conv->nbrf_status = NOPOSS;
	conv->nbrd = static_cast<double>(num);
	if (num == conv->nbrd)
		conv->nbrd_status = OK;
	else
	 	conv->nbrd_status = NOPOSS;
	return true;		
}

bool ScalarConverter::convertFloat(outData *conv) {
	(void) conv;
	return true;
}
bool ScalarConverter::convertDouble(outData *conv) {
	(void) conv;
	return true;
}
bool ScalarConverter::convertNone(outData *conv) {
	(void) conv;
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
