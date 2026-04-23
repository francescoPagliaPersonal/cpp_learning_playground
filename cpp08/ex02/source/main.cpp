/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 13:28:22 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/23 15:22:49 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

template<typename T>
void printIterable(std::string title, T & obj) {
	std::cout << "\nPRINTING "<< title << ": "<< std::endl;
	typename T::iterator it = obj.begin();
	typename T::iterator ite = obj.end();
	--ite;
	while (it != ite )
	{
		std::cout << *it << ", ";
		++it;
	}
	std::cout << *it << "." << std::endl;
}

int main(void)
{
	{
		
		std::list<int>	mylist;
		MutantStack<int> mstack;
		MutantStack<int>::iterator it;
		
		for (int i = 1; i < 100; i += 3) {
			mstack.push(i * 2.5);
			mylist.push_back(i * 2.5);
		}
		printIterable("MutantStack ", mstack);
		printIterable("std::List   ", mylist);		
	}
	{
		MutantStack<int> mstack;
		std::list<int>	mylist;
		
		mstack.push(5);
		mylist.push_back(mstack.top());
		mstack.push(17);
		mylist.push_back(mstack.top());
		
		std::cout << "mstack.top : " << mstack.top() <<  "\tsize: " << mstack.size()
				<<   "\nmylist.top : " << mylist.back() << "\tsize: " << mylist.size()
				<< std::endl;
		mstack.pop();
		mylist.pop_back();
		std::cout << "mstack.top : " << mstack.top() <<  "\tsize: " << mstack.size()
				<<   "\nmylist.top : " << mylist.back() << "\tsize: " << mylist.size()
				<< std::endl;
				
		mstack.push(3);
		mylist.push_back(mstack.top());
		mstack.push(5);
		mylist.push_back(mstack.top());
		mstack.push(737);
		mylist.push_back(mstack.top());
		mstack.push(0);
		mylist.push_back(mstack.top());
		std::cout << "mstack.top : " << mstack.top() <<  "\tsize: " << mstack.size()
				<<   "\nmylist.top : " << mylist.back() << "\tsize: " << mylist.size()
				<< std::endl;

		MutantStack<int>::iterator it = mstack.begin();
		std::cout << "shifting pointers: \nbegin + 1: " << *(++it) << "\nbegin    : " << *(--it) << std::endl;
		

		printIterable("MutantStack ", mstack);
		printIterable("std::List   ", mylist);	
	
		std::cout << "std::stack (reverted):" << std::endl;
		std::stack<int> s(mstack);
		while (s.size() != 0) {
			std::cout << s.top() << ", " ;
			s.pop();
		}
		std::cout << std::endl;
			
	}	
	return 0;
}
