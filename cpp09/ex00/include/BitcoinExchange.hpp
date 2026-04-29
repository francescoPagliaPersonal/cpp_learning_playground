/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 12:10:34 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/29 09:53:00 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_H
# define  BITCOINEXCHANGE_H

# define BITCO_DB "db/data.csv"
# define DATE_LEN 10
# define FIRST_YEAR 2000

# ifndef DEBUG
#  define DEBUG 0
# endif

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

	
	static std::map<std::string, double>	_dbBTC;
		
	static bool			_checkHeader(std::fstream & in, const std::string & title);
	static bool			_isvalidDate(const std::string & date);
	static bool 		_extractRate(const std::string & value, double & number, std::string & error);
	static bool			_parseLine(const std::string & line, const std::string & delimiter,
									std::string & date, double & rate, std::string & error);


};
#endif

