/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Setter.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 14:57:02 by fpaglia           #+#    #+#             */
/*   Updated: 2026/01/28 15:15:31 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Setter.class.hpp"

Setter::Setter(int myVal) : _val(myVal) {

	std::clog << "Constructor Setter complete" << std::endl;
	return ;
}

Setter::~Setter(void) {

	std::clog << "Destructor Setter complete" << std::endl;
}

int Setter::getVal(void) const {

	return (_val);
}

bool Setter::setVal(int num) {

	if (num < 0) {
		std::clog << "Values below 0 are not accepted" << std::endl;
		return (false);
	}
	_val = num;
	std::clog << "Value updated" << std::endl;
	return (true);
}
