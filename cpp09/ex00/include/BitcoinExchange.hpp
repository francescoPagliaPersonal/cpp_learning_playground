/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 12:10:34 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/27 12:43:20 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_H
# define  BITCOINEXCHANGE_H

# define BITCO_DB "../data.csv"
# include <map>
# include <iostream>

class BitcoinExchange {
	
	public:
	BitcoinExchange(void);
	BitcoinExchange(const BitcoinExchange & obj);
	~BitcoinExchange(void);
	BitcoinExchange&	operator=(const BitcoinExchange & obj);

	static void	convert(const char *file);
	
	private:

	
	static std::map<std::string, double>	_btcDB;
	std::map<std::string, double>			_inDB;
	
	
};
#endif

