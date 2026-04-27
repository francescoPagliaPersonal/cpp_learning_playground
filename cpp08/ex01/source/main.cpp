/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 11:40:24 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/27 11:44:34 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <list>
#include <exception>
#include <iostream>

int main(void)
{
	Span myobj(5000);
	Span Giantobj(110000);
	Span smallObj(5);
	int counter = 0;
	double arr[] = {1.5,2.3,3.1,4.9,5.6,6.4,7.3,8.2,9.1,10.45};
	int arr1[] = {1,2,3,4,5,6,7,8,9,105};
	
	{
		std::cout << "\n\n========== T" << counter << " THROW DATA TYPE =============\n" << std::endl; ++counter;

		try { myobj.addRange(&arr[0], &arr[9] ); }
		catch (std::exception & e) 
			{ std::cout << "ERROR: " << e.what() << std::endl; }
	}	
	{
		std::cout << "\n\n========== T" << counter << " THROW WRONG RANGE =============\n" << std::endl; ++counter;
		
		try { myobj.addRange(&arr1[9], &arr1[6] ); }
		catch (std::exception & e) 
			{ std::cout << "ERROR: " << e.what() << std::endl; }
	}
	{
		std::cout << "\n\n========== T" << counter << " THROW OUT OF RANGE =============\n" << std::endl; ++counter;

		try { smallObj.addRange(&arr1[0], &arr1[9] ); }
		catch (std::exception & e) 
			{ std::cout << "ERROR: " << e.what() << std::endl; }
	}
	{
		std::cout << "\n\n========== T" << counter << " THROW NOT ENOUGH ITEMS =============\n" << std::endl; ++counter;
		
		smallObj.addNumber(84);
		try { smallObj.longestSpan();}
		catch (std::exception & e) 
			{ std::cout << "ERROR: " << e.what() << std::endl; }

		try { smallObj.shortestSpan();}
		catch (std::exception & e) 
			{ std::cout << "ERROR: " << e.what() << std::endl; }
	}
	{
		std::cout << "\n\n========== T" << counter << " THROW TOO MANY NUMBERS =============\n" << std::endl; ++counter;

		Span sp = Span(3);
		try {
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
		catch (std::exception & e) 
			{ std::cout << "ERROR: " << e.what() << std::endl; }
	}
	{
		std::cout << "\n\n========== T" << counter << " ADD NUMBERS =============\n" << std::endl; ++counter;

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
	{	
		std::cout << "\n\n========== T" << counter << " ADD RANGE =============\n" << std::endl; ++counter;
		
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
		try {
		
			myobj.addNumber(46);
			myobj.addRange(test.begin(), test.end());
			std::cout 
					<< "\nInput deque:   " << test.size() << " items:\n"
					<< myobj.printArray(5)
					<< "\nshortest span: " << myobj.shortestSpan() 
					<< "\nlongest span : " << myobj.longestSpan() << std::endl;
		} 
		catch (std::exception & e) 
			{ std::cout << "ERROR: " << e.what() << std::endl; }
		
	}
	{	
		std::cout << "\n\n========== T" << counter << " ADD HUGE RANGE =============\n" << std::endl; ++counter;
		
		std::list<int> test;
		for (int j = 1; j < 20000; j +=2) {
			if (j % 3 != 0) {
				for (int i = 0; i < 10; ++i)
					test.push_back((arr[i] * 10 * j));
			}
			else {
				for (int i = 0; i < 10; ++i)
					test.push_front((arr[i] * 10 * j));
			}
		}

		Giantobj.addNumber(46);
		try 
		{
			Giantobj.addRange(test.begin(), test.end());
			std::cout 
					<< "\nInput deque:   " << test.size() << " items:\n"
					<< Giantobj.printArray(5)
					<< "\nshortest span: " << Giantobj.shortestSpan() 
					<< "\nlongest span : " << Giantobj.longestSpan() << std::endl;
		}
		catch (std::exception & e) 
			{ std::cout << "ERROR: " << e.what() << std::endl; }
		
	}
	return 0;	
}
