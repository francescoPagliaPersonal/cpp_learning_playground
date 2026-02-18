/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 10:45:45 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/18 15:55:54 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>
#include <iterator>

void test(const Point& a, const Point& b, const Point& c, const Point& p, 
	bool expected)
{
	bool result = p.bsp(a, b, c, p);

	std::cout << "Point (" 
			  << p.getXpos() << ", " 
			  << p.getYpos() << ") ->\t";

	if (result == expected)
		std::cout << "✅ OK";
	else
		std::cout << "❌ FAIL";

	std::cout << " (expected: " << expected 
			  << ", got: " << result << ")" << std::endl;
}

int main(void)
{
	Point a(0.0f, 0.0f);
	Point b(10, 0);
	Point c(0, 10);
	Point z = b;

	std::cout << "Triangle\n"
			<< "point A\tx: " << a.getXpos() << "\ty: " << a.getXpos() << "\n"
			<< "point B\tx: " << b.getXpos() << "\ty: " << b.getXpos() << "\n"
			<< "point C\tx: " << c.getXpos() << "\ty: " << c.getXpos() << "\n" 
			<< "point Z\tx: " << z.getXpos() << "\ty: " << z.getXpos() << "\n" 
			<< std::endl;
	std::cout << "\n--- BASIC TESTS ---\n";
	test(a, b, c, Point(1, 1), true);    // inside
	test(a, b, c, Point(5, 5), false);   // on hypotenuse
	test(a, b, c, Point(10, 10), false); // outside
	test(a, b, c, Point(0, 0), false);   // vertex
	test(a, b, c, Point(0, 5), false);   // edge

	std::cout << "\n--- ORIENTATION TEST ---\n";
	test(b, a, c, Point(1, 1), true);     // reversed order

	std::cout << "\n--- DEGENERATE TRIANGLE ---\n";
	Point d(0, 0);
	Point e(5, 5);
	Point f(10, 10); // collinear
	test(d, e, f, Point(6, 6), false);

	std::cout << "\n--- FLOAT PRECISION TEST ---\n";
	test(a, b, c, Point(0.1f, 0.1f), true);
	test(a, b, c, Point(9.999f, 0.001f), false);

	std::cout << "\n--- DONE ---\n";
	return 0;
}