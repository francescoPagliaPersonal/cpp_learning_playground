/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Compare.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 10:50:01 by fpaglia           #+#    #+#             */
/*   Updated: 2026/01/29 11:14:06 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Compare.class.hpp"

Compare::Compare(int num) : _val(num) {

	std::clog << "Compare instance constructed" << std::endl;
	return ;
}

Compare::~Compare(void) {

	std::clog << "Compare instance destroyed" << std::endl;
	return ;
}

int	Compare::getval(void) {

	return (this->_val);
}

void Compare::setval(int num) {

	_val = num;
	std::clog << "modified _val to: " << _val << std::endl;
	return ;
}

int Compare::check(Compare *ptr) {

	if (this->_val > ptr->getval())
		return (1);
	if (this->_val < ptr->getval())
		return (-1);
	return (0);
}
