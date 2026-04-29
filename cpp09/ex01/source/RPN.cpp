/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 10:00:04 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/29 10:25:23 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "RPN.hpp"
#include <stdexcept>

std::stack<char> RPN::_items;
std::stack<char> RPN::_opQueue;


std::string RPN::parseInput(const char *str) {
	if (!str || !*str)
		throw std::runtime_error("Missing input.");
	std::string input(str);
	std::string::size_type pos = input.find_first_not_of(" 0123456789+-*/");
	if (pos == input.npos)
		throw std::runtime_error("Malformed input.");
	return input;
}

