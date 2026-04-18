/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 11:42:59 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/16 13:19:31 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <cctype>
#include <iostream>


class Yes { 
	public:
	Yes(void) : _num(0) {};
	Yes(int num) : _num(num) {}; 
	Yes(Yes const & obj) : _num(obj._num) {};
	~Yes(void) {};
	void	setNum(int num) {_num = num;};
	int		getNum(void) const {return _num;};
	
	private: 
	int _num;
};

void add(int & num)
{
	num += 5;
}
void addYes(Yes & obj)
{
	obj.setNum(5);
}

void print(int const & num)
{
	std::cout << num << std::endl;
}

void printYes(Yes const & obj) {
	std::cout << obj.getNum() << std::endl;
}
int uppercase(char & c )
{
	int a = static_cast<int>(c);
	c = static_cast<unsigned char>(std::toupper(a));
	return (a);
}

void increment(int & x) { x++;}
int increment(Yes & x) { x.setNum(x.getNum() * 2); return 1;}

#define MYCLASS_SIZE 10

int main(void)
{
	int num[] = {0,1,2,3,4};
	Yes myClass[MYCLASS_SIZE] ;
	char str[] = "ciaobello!";
	::iter(num, sizeof(num)/sizeof(num[0]), print);
	::iter(num, sizeof(num)/sizeof(num[0]), add);
	::iter(num, sizeof(num)/sizeof(num[0]), print);
	::iter(str, sizeof(str)/sizeof(str[0]), uppercase);
	std::cout << str << std::endl;
	::iter(myClass, MYCLASS_SIZE,  addYes);
	::iter(myClass, MYCLASS_SIZE,  static_cast<int(*)(Yes&)>(increment));
	::iter(myClass, MYCLASS_SIZE, printYes);
	::iter(num, sizeof(num)/sizeof(num[0]), print);

}