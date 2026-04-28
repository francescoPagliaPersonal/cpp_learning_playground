/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 13:53:40 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/28 11:44:54 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <cerrno>
#include <cctype>
#include <fstream>
#include <iostream>
#include <istream>
#include <sstream>
#include <stdexcept>

std::map<std::string, double> 	BitcoinExchange::_dbBTC;

bool		BitcoinExchange::_checkHeader(std::fstream & in, const std::string & title) {
	std::string myline;
	std::getline(in, myline);
	return myline == title;
}


void BitcoinExchange::convert(const char* file) {
	(void)file;
	return ;	
}