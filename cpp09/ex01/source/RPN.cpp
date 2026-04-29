/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 10:00:04 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/29 12:59:20 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <stdexcept>
#include <string>
#include <iostream>

std::stack<int> RPN::_items;

int calculate(int left, int right, char oper) {
	if (oper == '/' && right == 0)
		throw std::runtime_error("Division by zero now allowed.");
	std::string str("+-*/");
	int result = 0;
	switch (str.find_first_of(oper)) {
		case 0: 
			result = left + right;
			break;
		case 1: 
			result = left - right;
			break;
		case 2: 
			result = left * right;
			break;
		case 3: 
			result = left / right;
			break;
		default:
			throw std::runtime_error("Unexpected operator found.");
	}
	if (DEBUG)
		std::cout << left << " " << oper << " " << right << " = " << result << std::endl;
	return result;
}

int RPN::result(const char *str) {

	// Basic string validation.
	
	if (!str || !*str)
		throw std::runtime_error("Missing input.");
	std::string input(str);
	std::string::size_type pos = input.find_first_not_of(" 0123456789+-*/");
	if (pos != input.npos)
		throw std::runtime_error("Malformed input.");
	
	// Perform the calculation while validating the spacing rules.
	
	pos = 0;
	while (pos + 1 != input.size()) {
		pos = input.find_first_not_of(" ", pos);
		
		if (std::isdigit(input[pos]) != 0)
			_items.push(static_cast<int>(input[pos] - '0'));
		else if (_items.size() < 2)
			throw std::runtime_error("Not enough items to perform calculation");
		else {
			int right = _items.top();
			_items.pop();
			int left = _items.top();
			_items.pop();
			_items.push(calculate(left, right, input[pos]));
		}
		
		if (pos + 1 == input.size())
			break;
		if (input[pos + 1] != ' ')
			throw std::runtime_error("Malformed input. Incorrect spacing");
		++pos;
	}

	// Check items count before returning.

	if (_items.size() != 1)
		throw std::runtime_error("Calculation incomplete, not all operand have been consumed.");
	return _items.top();
}
