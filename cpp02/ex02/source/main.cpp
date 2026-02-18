/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 10:45:45 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/18 16:24:12 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

std::string toBool(bool ret)
{
	return (ret == 1 ? "true" : "false");
}

int main( void ) {
	
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed const c(Fixed(4) / Fixed (2));
	Fixed d = c;
	Fixed e;
	e = d;
	
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << c / b << std::endl;
	std::cout << --d << std::endl;
	std::cout << d-- << std::endl;
	std::cout << d << "< " << a << toBool(d < a) << std::endl;
	std::cout << d << "> " << a << toBool(d > a) << std::endl;
	std::cout << d << "==" << a << toBool(d == a) << std::endl;
	std::cout << d << "!=" << a << toBool(d != a) << std::endl;
	std::cout << d << "==" << a << toBool(d == d) << std::endl;
	std::cout << d << "<=" << a << toBool(d <= d) << std::endl;
	std::cout << d << ">=" << a << toBool(d >= d) << std::endl;
	std::cout << d << "" << a << toBool(d > d) << std::endl;
	std::cout << d << "" << a << toBool(d < a) << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	
	return 0;
}