/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 13:28:22 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/27 11:53:13 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

template<typename T>
void printIterable(std::string title, T const & obj) {
	std::cout << "\nPRINTING "<< title << ": "<< std::endl;
	typename T::const_iterator it = obj.begin();
	typename T::const_iterator ite = obj.end();
	if (it == ite)
		return;
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
	int counter = 0;
	{
		std::cout << "\n\n========== T" << counter << " CREATE A MUTANT STACK AND COMPARE AGAINST A LIST =============\n" << std::endl; ++counter;
		
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
		std::cout << "\n\n========== T" << counter << " USE AVAILABLE MEMBER FUNCTION push, pop, top  =============\n" << std::endl; ++counter;

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

		printIterable("MutantStack ", mstack);
		printIterable("std::List   ", mylist);	
	
		std::cout << "\n\n========== T" << counter << " PLAY WITH ITERATOR ++it/--it  =============\n" << std::endl; ++counter;

		MutantStack<int>::iterator it = mstack.begin();
		std::cout << "shifting pointers: \nbegin + 1: " << *(++it) << "\nbegin    : " << *(--it) << std::endl;
	
		std::cout << "\n\n========== T" << counter << " COPY CONSTRUCTOR OF A STACK USING A MUTANT STACK  AND VICE VERSA =============\n" << std::endl; ++counter;
		
		std::cout << "std::stack (reverted):" << std::endl;
		
		std::stack<int> s(mstack);
		while (s.size() != 0) {
			std::cout << s.top() << ", " ;
			s.pop();
		}
		std::cout << std::endl;
		
		s = mstack;
		MutantStack<int> ms(s);
		MutantStack<int> ms2(ms);
		printIterable("copy constuctor of std::stack  ", ms);
		printIterable("copy constuctor of MutantStack ", ms2);
		
		std::cout << "\n\n========== T" << counter << " COPY ASSIGN OPERATOR =============\n" << std::endl; ++counter;

		MutantStack<int>	massign;
		MutantStack<int>	sassign;

		massign = mstack;
		sassign = s;

		printIterable("MutantStack ", mstack);
		printIterable("op= MutantStack  ", massign);	
		printIterable("op= std::Stack   ", sassign);	

	}	
	return 0;
}
