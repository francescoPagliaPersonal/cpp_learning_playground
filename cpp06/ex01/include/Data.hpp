/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 00:03:46 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/15 00:03:47 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include <string>
# include <ostream>

class Data {
	
	public:
	
	Data();
	Data(std::string str, int value);
	~Data();

	std::string				getStr(void) const;
	int						getValue(void) const;

	
	private:
	
	Data(const Data& obj);
	Data& operator=(const Data& obj);

	const int				_value;
	const std::string		_str;
};

std::ostream&		operator<<(std::ostream& ostream, const Data& obj);

#endif
