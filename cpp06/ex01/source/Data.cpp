/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 01:25:43 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/15 01:25:45 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(void)
	: _value(42), _str("Hello World") {} ;

Data::Data(std::string str, int value)
	: _value(value), _str(str) {} ;

Data::~Data(void) {};

std::string	Data::getStr(void) const {
	return _str;
};

int					Data::getValue(void) const {
	return _value;
};

std::ostream&		operator<<(std::ostream& ostream, const Data& obj) {
	ostream << "string: " << obj.getStr() << " Status: " << obj.getValue() ;
	return ostream;
};

