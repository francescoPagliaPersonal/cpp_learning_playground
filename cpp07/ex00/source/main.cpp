/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 19:21:13 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/20 10:11:35 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <algorithm>
#include <iostream>

class A {
	public: 
	A(int num)		: _num(num) {}; 
	A(const A& obj)	: _num(obj._num) {};
	A& operator=(const A& obj) {if (this != &obj) _num = obj._num; return *this;} 
	bool operator>(const A& obj) const {return _num > obj._num; } 
	bool operator<(const A& obj) const {return _num < obj._num; } 
	int getValue() const {return _num;}
	
	private: 
	int _num;
};

std::ostream& operator<<(std::ostream& stream, const A& obj) {
	stream << "Class value: " << obj.getValue() ;
	return stream;
}

int main(void)
{
	{
	std::cout << "\n========== T1 INT PAIR =============" << std::endl;
	int a = 2;
	int b = 3;
	std::cout << "\n ----- declared variables -----\n" << std::endl;
 	std::cout << "a = " << a << ", b = " << b << std::endl;
	::swap( a, b );
	std::cout << "\n ----- after swap -----\n" << std::endl;

	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max<int>( a, b ) << std::endl;
	}
	{
	std::cout << "\n========== T2 FLOAT PAIR =============" << std::endl;
	float a = 7.11f;
	float b = 6.43f;
	std::cout << "\n ----- declared variables -----\n" << std::endl;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	::swap( a, b );
	std::cout << "\n ----- after swap -----\n" << std::endl;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min<float>( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	}
	{
	std::cout << "\n========== T3 CHAR PAIR =============" << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	std::cout << "\n ----- declared variables -----\n" << std::endl;
	std::cout << "c = " << c << ", d = " << d << std::endl;
	::swap(c, d);
	std::cout << "\n ----- after swap -----\n" << std::endl;
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max<std::string>( c, d ) << std::endl;
	}
	{
	std::cout << "\n========== T4 CLASS PAIR =============" << std::endl;
	A a(5);
	A b(6);
	std::cout << "\n ----- declared variables -----\n" << std::endl;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	::swap( a, b );
	std::cout << "\n ----- after swap -----\n" << std::endl;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min<A>( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	}
	
	return 0;
}

