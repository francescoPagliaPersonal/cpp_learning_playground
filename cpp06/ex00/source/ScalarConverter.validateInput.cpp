/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.validateInput.cpp                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 16:26:41 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/14 16:49:40 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"


/* Given a string validate if the input is properly formatted.
 * Check if it is a litteral non numerical value or
 * Starts with a +/- sign (optional)
 * Has an interrupted series of numbers.
 * Has at most one dot "." (optional)
 * Ends with "f" (optional)
 *
 * Returns:
 * - true if the input data is formatted as expected.
 * - false in case of non conform input string.
 */
bool ScalarConverter::validateInput(const char* str) {
	
	_in_litteral = 0;
	_in_type = NOTATYPE;
	_in_str.assign(str);
	
	std::string& tmp = _in_str;
	std::string::iterator it = tmp.begin();
	
	if (!std::isdigit(static_cast<unsigned char>(*it))
		&& (std::isprint(static_cast<unsigned char>(*it)) 
		&& (it + 1 == tmp.end()))) {
		_in_type = CHAR;
		return true;
	}

	if (isLitterals(tmp))
		return true;
	
	if (*it == '+' || *it == '-'){
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
		else if (std::tolower(static_cast<unsigned char>(*it)) == 'f')
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
		if (std::tolower(static_cast<unsigned char>(*it)) == 'f') {
			char_f = 1;
			++it;	
		}
	}
	if (it != tmp.end())
		return false;
	
	dot == 1 ? _in_type = DOUBLE : _in_type = INTEGER;
	char_f == 1 ? _in_type = FLOAT : NULL;
	return true;
}
