/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.increment.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 13:19:41 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/17 11:04:57 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed&	Fixed::operator++(void) {
	 ++this->_rawbits;
	 return (*this);
}

Fixed&	Fixed::operator--(void) {
	 --this->_rawbits;
	 return (*this);
}

Fixed	Fixed::operator++(int) {
	Fixed temp = *this;
	++this->_rawbits;	
	return (temp);
}

Fixed	Fixed::operator--(int) {
	Fixed temp = *this;
	--this->_rawbits;	
	return (temp);
}