/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 11:40:24 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/22 14:40:27 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <deque>
#include <exception>
#include <iostream>

int main(void)
{
	Span myobj(500);
	double arr[] = {1.5,2.3,3.1,4.9,5.6,6.4,7.3,8.2,9.1,10.45};
	int arr1[] = {1,2,3,4,5,6,7,8,9,105};
	
	{
	try { myobj.addRange(&arr[0], &arr[9] ); }
	catch (std::exception & e) 
		{ std::cout << "ERROR: " << e.what() << std::endl; }
	}	
	{
	try { myobj.addRange(&arr1[9], &arr1[6] ); }
	catch (std::exception & e) 
		{ std::cout << "ERROR: " << e.what() << std::endl; }
	}	
	std::deque<int> test;
	for (int i = 0; i < 10; ++i)
		test.push_back((arr[i] * 10));

	myobj.addNumber(46);
	myobj.addRange(test.begin(), test.end());
	std::cout << myobj 
			<< "\n" << myobj.shortestSpan() 
			<< "\n" << myobj.longestSpan() << std::endl;
	
	std::cout << test	[0] << std::endl;
	return 0;	
}
