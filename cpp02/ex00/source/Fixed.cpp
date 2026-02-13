/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 10:47:09 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/13 10:17:48 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_fractbit = 8;

Fixed::Fixed(void) : _rawbits(0) 
{
	std::cout << "Default constructor called" << std::endl;
}

/* For as much as I understod this is the best approach to create the copy constructor.
 * Eventually to have a fully matching approach to the output the overload = is required
 */
// Fixed::Fixed(const Fixed& obj) 
// 	: _rawbits(obj.getRawBits()) 
// {
// 	std::cout << "Copy constructor called" << std::endl;
// }

Fixed::Fixed(const Fixed& obj) 
{
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

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

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_rawbits;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_rawbits= raw;
}

