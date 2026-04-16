/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 19:21:13 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/16 09:38:07 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>
#include <ostream>

class A {
	public: 
	A(int num) : _num(num) {}; 
	A(const A& obj) : _num(obj._num) {};
	A& operator>(A& obj) {return _num > obj._num ? *this : obj; } 
	A& operator<(A& obj) {return _num < obj._num ? *this : obj; } 
	int getValue() const {return _num;}
	
	private: 
	const int _num;
};

std::ostream& operator<<(std::ostream& stream, const A& obj) {
	stream << "Class value: " << obj.getValue() ;
	return stream;
}

int main(void)
{
	{
	int a = 2;
	int b = 3;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	}
	std::string c = "chaine1";
	std::string d = "chaine2";
	std::cout << "c = " << c << ", d = " << d << std::endl;
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	{
	A a(5);
	A b(6);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	}
	return 0;
}
