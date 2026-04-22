/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 11:40:24 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/22 15:57:41 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <list>
#include <exception>
#include <iostream>

int main(void)
{
	Span myobj(5000);
	Span smallObj(5);
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
	{
		try { smallObj.addRange(&arr1[0], &arr1[9] ); }
		catch (std::exception & e) 
			{ std::cout << "ERROR: " << e.what() << std::endl; }
	}
	{
		smallObj.addNumber(84);
		try { smallObj.longestSpan();}
		catch (std::exception & e) 
			{ std::cout << "ERROR: " << e.what() << std::endl; }

		try { smallObj.shortestSpan();}
		catch (std::exception & e) 
			{ std::cout << "ERROR: " << e.what() << std::endl; }
	}
	{	
		std::list<int> test;
		for (int j = 1; j < 900; j +=2) {
			if (j % 3 != 0) {
				for (int i = 0; i < 10; ++i)
					test.push_back((arr[i] * 10 * j));
			}
			else {
				for (int i = 0; i < 10; ++i)
					test.push_front((arr[i] * 10 * j));
			}
		}

		myobj.addNumber(46);
		myobj.addRange(test.begin(), test.end());
		std::cout 
				<< "\nInput deque:   " << test.size() 
				<< "\nshortest span: " << myobj.shortestSpan() 
				<< "\nlongest span : " << myobj.longestSpan() << std::endl;
		
	}
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout 
				<< "\ninput data:    " << sp
				<< "\nshortest span: " << sp.shortestSpan()
				<< "\nlongest span : " << sp.longestSpan() << std::endl;
	}
	return 0;	
}
