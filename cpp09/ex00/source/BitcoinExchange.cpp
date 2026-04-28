/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 13:53:40 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/28 18:04:03 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::map<std::string, double> 	BitcoinExchange::_dbBTC;

bool		BitcoinExchange::_checkHeader(std::fstream & in, const std::string & title) {
	std::string myline;
	std::getline(in, myline);
	return myline == title;
}



