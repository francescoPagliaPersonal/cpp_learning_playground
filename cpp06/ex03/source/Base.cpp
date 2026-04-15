/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 10:07:12 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/15 10:54:57 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>

Base::~Base(void) {};

Base*	Base::generate(void) {
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	int num = std::rand() % 3;
	std::cout << "selected class: " << num << std::endl;
	switch (num) {
		case 0 :
			return new A;
		case 1 :
			return new B;
		case 2 :
			return new C;
		default :
			return NULL;
	}
}

void	Base::identify(Base * p) {
	{
	A* a = dynamic_cast<A *>(p);
	if (a != NULL)
		std::cout << "pointer of type A" << std::endl;
	}
	{
	B* a= dynamic_cast<B *>(p);
	if (a != NULL)
		std::cout << "pointer of type B" << std::endl;
	}
	{
	C* a = dynamic_cast<C *>(p);
	if (a != NULL)
		std::cout << "pointer of type C" << std::endl;
	}
}

void	Base::identify(Base & p) {
	try {
		A& a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "reference of type A" << std::endl;
		return;
	}
	catch (std::exception& bc) {};

	try {
		B& a = dynamic_cast<B &>(p);
		(void)a;
		std::cout << "reference of type B" << std::endl;
		return;
	}
	catch (std::exception& bc) {};
	
	try {
		C& a = dynamic_cast<C &>(p);
		(void)a;
		std::cout << "reference of type C" << std::endl;
		return;
	}
	catch (std::exception& bc) {};
}