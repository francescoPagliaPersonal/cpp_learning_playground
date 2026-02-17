/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 10:45:45 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/17 16:40:57 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

int main( void ) {
	
	Point a(7, 5.5f);
	Point b(-12.3f, 6.2f);
	Point c;
	Point p(0, 3);
	std::cout << p.bsp(a, b, c, p)
			<< std::endl;
	return 0;
}