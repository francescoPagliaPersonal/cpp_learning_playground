/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 12:10:34 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/28 15:29:23 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_H
# define  BITCOINEXCHANGE_H

# define BITCO_DB "db/data.csv"
# define DATE_LEN 10

# include <map>
# include <fstream>
# include <iostream>
# include <cstdlib>

class BitcoinExchange {
	
	public:
	static void	init(void);
	static void	convert(const char *file);
	

	private:
	BitcoinExchange(void);
	BitcoinExchange(const BitcoinExchange & obj);
	~BitcoinExchange(void);
	BitcoinExchange&	operator=(const BitcoinExchange & obj);

	std::fstream		_fileBTC;
	std::fstream		_fileIN;
	
	static std::map<std::string, double>	_dbBTC;
	std::map<std::string, double>			_dbIN;
		
	static bool			_checkHeader(std::fstream & in, const std::string & title);
	static std::string	_extractDate(const std::string & date);
	static bool			_followsValidDelimiter(const std::string & source, const std::string & pattern);
	static double 		_extractRate(const std::string & source, int offset);
/*	bool 				_parseLine(const std::string & line, const std::string & delimiter,
									std::string & date, double & rate, std::string & error);
*/	
};
#endif

