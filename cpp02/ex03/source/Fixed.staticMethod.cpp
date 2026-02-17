/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.staticMethod.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 12:33:56 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/17 12:43:00 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed&		Fixed::max(Fixed& obj1, Fixed& obj2) {
	return (obj1 > obj2 ? obj1 : obj2);
};

const Fixed&	Fixed::max(const Fixed& obj1, const Fixed& obj2) {
	return (obj1 > obj2 ? obj1 : obj2);
}

Fixed&		Fixed::min(Fixed& obj1, Fixed& obj2) {
	return (obj1 < obj2 ? obj1 : obj2);
}

const Fixed&	Fixed::min(const Fixed& obj1, const Fixed& obj2) {
	return (obj1 < obj2 ? obj1 : obj2);
}
