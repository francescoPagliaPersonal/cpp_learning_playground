/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 10:47:09 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/18 16:09:57 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

// STATIC VALUES -------------------------------------------------------------/

const int	Fixed::_fractbit = 8;

// CONSTRUCTORS  -------------------------------------------------------------/

Fixed::Fixed(void)				: _rawbits(0) {}

Fixed::Fixed(const int nbr)		: _rawbits(_toRawBits(nbr)) {}

Fixed::Fixed(const float nbr)	: _rawbits(_toRawBits(nbr)) {}

Fixed::Fixed(const Fixed& obj)	: _rawbits(obj._rawbits) {}

Fixed& Fixed::operator=(const Fixed& obj) {
	if (this != &obj)	
		this->_rawbits = obj.getRawBits();
	return (*this);
}

Fixed::~Fixed(void) {}

// METHODS -----------------------------------------------------------------/

int	Fixed::getRawBits(void) const {
	return this->_rawbits;
}

void Fixed::setRawBits(int const raw) {
	this->_rawbits= raw;
}

int Fixed::_toRawBits(const int nbr) {
	return (nbr << _fractbit);
}

int Fixed::_toRawBits(const float nbr) {
	return (roundf(nbr * (1 <<  _fractbit)));
}

int Fixed::toInt(void) const {
	return (this->getRawBits() >> _fractbit);
}

float Fixed::toFloat(void) const {
	return (((float)this->getRawBits()) / (1 <<  _fractbit));
}

std::ostream&	operator<<(std::ostream& ostream, Fixed const &obj)
{
	ostream << obj.toFloat();
	return ostream;
}