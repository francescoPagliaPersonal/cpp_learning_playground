/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 10:45:45 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/27 14:09:56 by fpaglia          ###   ########.fr       */
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
	Fixed f(10.67f);
	
	std::cout << "a:        " << a << std::endl;
	std::cout << "++a       " << ++a << std::endl;
	std::cout << "a:        " << a << std::endl;
	std::cout << "a++:      " << a++ << std::endl;
	std::cout << "value a:  " << a << std::endl;
	std::cout << "value b:  " << b << std::endl;
	std::cout << "value c:  " << c << std::endl;
	std::cout << "c/b:      "<< c / b << std::endl;
	std::cout << "value d:  " << d << std::endl;
	std::cout << "--d  :    " << --d << std::endl;
	std::cout << "d--  :    " << d-- << std::endl;
	std::cout << "value d:  " << d << std::endl;
	std::cout << "value e:  " << e << std::endl;
	std::cout << "value f:  " << f << std::endl;
	std::cout << "f+e  :    " << f + e << " " << std::endl;
	std::cout << "value e:  " << e << std::endl;
	std::cout << "value f:  " << f << std::endl;
	std::cout << "f-(e*2):  " << f - (e * 2) << " " << std::endl;
	std::cout << d << " <  " << a << " \t" << toBool(d < a)  << std::endl;
	std::cout << d << " >  " << a << " \t" << toBool(d > a)  << std::endl;
	std::cout << d << " == " << a << " \t" << toBool(d == a)  << std::endl;
	std::cout << d << " != " << a << " \t" << toBool(d != a)  << std::endl;
	std::cout << d << " == " << d << " \t" << toBool(d == d)  << std::endl;
	std::cout << d << " <= " << d << " \t" << toBool(d <= d)  << std::endl;
	std::cout << d << " >= " << d << " \t" << toBool(d >= d)  << std::endl;
	std::cout << d << " >  "  << d << " \t" << toBool(d > d)  << std::endl;
	std::cout << d << " <  "  << a << "\t" << toBool(d < a)  << std::endl;
	std::cout << "max(a,d)"  << "\t\t" << Fixed::max( a, d )  << std::endl;
	std::cout << "min(a,d)"  << "\t\t" << Fixed::min( a, d )  << std::endl;
	std::cout << "const max(c,b)"  << "\t\t" << Fixed::max( c, b )  << std::endl;
	std::cout << "const min(c,b)"  << "\t\t" << Fixed::min( c, b )  << std::endl;
	
	return 0;
}