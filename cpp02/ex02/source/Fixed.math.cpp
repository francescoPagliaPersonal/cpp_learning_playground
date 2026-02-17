/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.math.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 13:15:57 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/17 12:09:50 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <climits>

Fixed	Fixed::operator+(const Fixed& obj) const {
	long	nbr;
	Fixed	tmp;

	nbr = (static_cast<long>(this->_rawbits) + static_cast<long>(obj._rawbits)) >> Fixed::_fractbit;
	if (nbr > INT_MAX)
		nbr = INT_MAX;
	else if (nbr < INT_MIN)
		nbr = INT_MIN;
	
	tmp._rawbits = nbr;
	return (tmp);
}

Fixed	Fixed::operator-(const Fixed& obj) const {
	long	nbr;
	Fixed	tmp;

	nbr = (static_cast<long>(this->_rawbits) - static_cast<long>(obj._rawbits)) >> Fixed::_fractbit;
	if (nbr > INT_MAX)
		nbr = INT_MAX;
	else if (nbr < INT_MIN)
		nbr = INT_MIN;
	
	tmp._rawbits = nbr;
	return (tmp);
}

Fixed	Fixed::operator*(const Fixed& obj) const {
	long	nbr;
	Fixed	tmp;

	nbr = (static_cast<long>(this->_rawbits) * static_cast<long>(obj._rawbits)) >> Fixed::_fractbit;
	if (nbr > INT_MAX)
		nbr = INT_MAX;
	else if (nbr < INT_MIN)
		nbr = INT_MIN;
	
	tmp._rawbits = nbr;
	return (tmp);
}

Fixed	Fixed::operator/(const Fixed& obj) const {
	Fixed tmp;
	
	if (obj._rawbits == 0) {
		tmp._rawbits = this->_rawbits > 0 ? INT_MAX : INT_MIN;
	}
	else {
		long	nbr;
		long	a = static_cast<long>(this->_rawbits) << _fractbit;
		long	b = static_cast<long>(obj._rawbits);
		nbr = a / b  ;
		if (nbr > INT_MAX)
			nbr = INT_MAX;
		else if (nbr < INT_MIN)
			nbr = INT_MIN;
		
		tmp._rawbits = nbr;
	}
	return (tmp);
}