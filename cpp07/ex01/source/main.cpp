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

void add(int & num)
{
	num += 5;
}
void print(int const & num)
{
	std::cout << num << std::endl;
}

int main(void)
{
	int num[] = {0,1,2,3,4};
	// std::string str("ciaobello");
	// int *numeri = num;
	// int & numref = numeri;
	// int & numeri = num;
	::iter(num, sizeof(num)/sizeof(num[0]), print);
	::iter(num, sizeof(num)/sizeof(num[0]), add);
	::iter(num, sizeof(num)/sizeof(num[0]), print);
	// ::iter(num, sizeof(num)/sizeof(num[0]), [](int &x){ x++; });
	// ::iter(num, sizeof(num)/sizeof(num[0]), print);

	// std::cout << str[0] << " " << str[1] << std::endl;
}