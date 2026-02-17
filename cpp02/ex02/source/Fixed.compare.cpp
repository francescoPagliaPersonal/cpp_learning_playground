/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.compare.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 13:15:51 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/17 11:12:24 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

bool	Fixed::operator>(const Fixed& obj) const {
	return (this->_rawbits > obj._rawbits);
}

bool	Fixed::operator<(const Fixed& obj) const {
	return (this->_rawbits < obj._rawbits);
}

bool	Fixed::operator>=(const Fixed& obj) const {
	return (this->_rawbits >= obj._rawbits);
}

bool	Fixed::operator<=(const Fixed& obj) const {
	return (this->_rawbits <= obj._rawbits);
}

bool	Fixed::operator==(const Fixed& obj) const {
	return (this->_rawbits == obj._rawbits);
}

bool	Fixed::operator!=(const Fixed& obj) const {
	return (this->_rawbits != obj._rawbits);
}