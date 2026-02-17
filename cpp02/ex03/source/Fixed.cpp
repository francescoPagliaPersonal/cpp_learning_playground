/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 10:47:09 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/17 11:04:06 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

// STATIC VALUES -------------------------------------------------------------/

const int	Fixed::_fractbit = 8;

// CONSTRUCTORS  -------------------------------------------------------------/

Fixed::Fixed(void) : _rawbits(0) 
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int nbr) : _rawbits(_toRawBits(nbr)) 
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float nbr) : _rawbits(_toRawBits(nbr))
{
	std::cout << "Float constructor called" << std::endl;
}

/* For as much as I understod this is the best approach to create the copy constructor.
 * Eventually to have a fully matching approach to the output the overload = is required
 */
Fixed::Fixed(const Fixed& obj) 
	: _rawbits(obj._rawbits) 
{
	std::cout << "Copy constructor called" << std::endl;
}

// Fixed::Fixed(const Fixed& obj) 
// {
// 	std::cout << "Copy constructor called" << std::endl;
// 	*this = obj;
// }

Fixed& Fixed::operator=(const Fixed& obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	
	if (this != &obj)	
		this->_rawbits = obj.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

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