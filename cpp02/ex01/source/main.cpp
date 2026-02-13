/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 10:45:45 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/13 13:03:34 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main( void ) {
	// Fixed a;
	// Fixed const b(10 );
	// Fixed const c(42.42f);
	// Fixed const d(42.5f);
	// // Fixed const d( b );
	// a = Fixed( 1234.54f );
	
	// std::cout << "a -> stored: " << a.getRawBits() << "\tintval:" << a.toInt() << std::endl;
	// std::cout << "a -> stored: " << b.getRawBits() << "\tintval:" << b.toInt() << std::endl;
	// std::cout << "a -> stored: " << c.getRawBits() << "\tintval:" << c.toInt() << std::endl;
	// std::cout << "a -> stored: " << d.getRawBits() << "\tintval:" << d.toInt() << std::endl;
	// std::cout << "a -> stored: " << a.getRawBits() << "\tfloval:" << a.toFloat() << std::endl;
	// std::cout << "a -> stored: " << b.getRawBits() << "\tfloval:" << b.toFloat() << std::endl;
	// std::cout << "a -> stored: " << c.getRawBits() << "\tfloval:" << c.toFloat() << std::endl;
	// std::cout << "a -> stored: " << d.getRawBits() << "\tfloval:" << d.toFloat() << std::endl;
	
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );
	a = Fixed( 1234.4321f );

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	return 0;
}
