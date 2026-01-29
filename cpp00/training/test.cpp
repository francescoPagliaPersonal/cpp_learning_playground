/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 17:26:37 by fpaglia           #+#    #+#             */
/*   Updated: 2026/01/29 11:22:15 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Trial.class.hpp"
#include "InitLst.class.hpp"
#include "Setter.class.hpp"
#include "Compare.class.hpp"
void prnt_comp(int num, char p)
{
	char str1[] = "phisically";
	char str2[] = "structurally";
	char *str;

	if (p == 'p')
		str = str1;
	else str = str2;
	
	if (num == 0)
		std::cout << "instancess are " << str << " equal" << std::endl;
	else 
		std::cout << "instancess are " << str << " NOT equal" << std::endl;

}


int main(void) {
//	HELLO WORLD
/*	char buff[512];

	std::cout << "Hello World" << std::endl;
	std::cout << "digit a word: ";
	std::cin  >> buff;
	std::cout << "you wrote: [\"" << buff << "\"]" << std::endl;
*/

//	FIRST CLASS
/*	Trial a;
	a.foo = 10;
	Trial b;	
	a.foofunct();
	b.foofunct();
	std::cout << "value of sum b: " << b.sum(10,5) << std::endl;
*/

//	PRIVATE VS PUBLIC
/*
	InitLst lst(1, 'p', 1.5);
	lst.report();
//	int casa = lst._set_private(5); *	this code is not possible because the 
//										function is marked as private 
	Setter value(2);
	std::cout << "value is: " << value.getVal() << '\n';
	value.setVal(10);
	std::cout << "value is: " << value.getVal() << '\n';
	value.setVal(-20);
*/

//	COMPARISON
	Compare one(46);
	Compare	two(48);
	
	std::cout << "show return: " << (&one == &one) << std::endl;
	prnt_comp(!(&one == &one), 'p');
	prnt_comp(!(&one == &two), 'p');

	prnt_comp(one.check(&one), 's');
	prnt_comp(one.check(&two), 's');
	two.setval(46);
	prnt_comp(one.check(&two), 's');
	return (0);
}
