/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 11:42:59 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/20 11:48:16 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <cctype>
#include <cstddef>
#include <iostream>

static int id = 0;
static std::string msg;

class Yes { 
	
	public:
	Yes(void)		: _num(0)	{};
	Yes(int num)	: _num(num)	{}; 
	Yes(Yes const & obj)
					: _num(obj._num) {};
	~Yes(void) {};
	Yes&	operator++(void) { _num += 1; return *this; }
	
	void	setNum(int num)		{_num = num;};
	int		getNum(void) const	{return _num;};
	
	
	private: 
	int _num;
};

void addInt(int & num)
{
	num += 10;
}
void addYes(Yes & obj)
{
	obj.setNum(obj.getNum() + 5);
}

void print(int const & num)
{
	std::cout << "[" << id << "] " << msg << ": "  << num << std::endl;
	id++;
}

void printYes(Yes const & obj) {
	std::cout << "[" << id << "] " << msg << ": " << obj.getNum() << std::endl;
	id++;
}

int uppercase(char & c )
{
	int a = static_cast<int>(c);
	c = static_cast<unsigned char>(std::toupper(a));
	return (a);
}

void increment(int & x) { x++;}
int increment(Yes & x) { x.setNum(x.getNum() * 2); return 1;}

#define MYCLASS_SIZE 4

int main(void)
{
	{
		std::cout << "\n========== T1 INT ARRAY =============\n" << std::endl;
		
		int num[] = {0,1,2,3,4};
		id = 0; msg.assign("source");
		::iter(num, sizeof(num)/sizeof(num[0]), print); 
		::iter(num, sizeof(num)/sizeof(num[0]), addInt);
		id = 0; msg.assign("add 10");
		::iter(num, sizeof(num)/sizeof(num[0]), print);
	}
	{
		std::cout << "\n========== T2 MY CLASS ARRAY =============\n" << std::endl;

		Yes myClass[MYCLASS_SIZE] ;
		for (std::size_t i = 0; i < MYCLASS_SIZE; ++i)
			myClass[i].setNum(i * 2);
		id = 0; msg.assign("source");
		::iter(myClass, MYCLASS_SIZE, printYes);
		::iter(myClass, MYCLASS_SIZE,  addYes);
		id = 0; msg.assign("add  5");
		::iter(myClass, MYCLASS_SIZE, printYes);
		::iter(myClass, MYCLASS_SIZE,  static_cast<int(*)(Yes&)>(increment));
		id = 0; msg.assign("double");
		::iter(myClass, MYCLASS_SIZE, printYes);
		
	}
	{
		std::cout << "\n========== T3 SINGLE STRING ARRAY =============\n" << std::endl;
		
		char str[] = "ciaobello!";
		std::cout << "source  : " <<str << std::endl;
		::iter(str, sizeof(str)/sizeof(str[0]), uppercase);
		std::cout << "toupper : " << str << std::endl;
	}
	
	{
		/*
		// requires the -std=c++11 in the make file for showcasing purposes
		std::cout << "\n========== T4 LAMBDA FUNCTION C++11(+) ONLY =============\n" << std::endl;
		
		int num[] = {0,1,2,3,4};
		id = 0; msg.assign("source");
		::iter(num, sizeof(num)/sizeof(num[0]), print); 
		::iter(num, sizeof(num)/sizeof(num[0]), [](int &a)->void{a *= 4;}); 
		id = 0; msg.assign("labda ");
		::iter(num, sizeof(num)/sizeof(num[0]), print); 
		*/
	}
}