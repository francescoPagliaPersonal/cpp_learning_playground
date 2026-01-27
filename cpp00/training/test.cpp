/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 17:26:37 by fpaglia           #+#    #+#             */
/*   Updated: 2026/01/27 10:43:00 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Trial.class.hpp"

int main(void) {
/*	char buff[512];

	std::cout << "Hello World" << std::endl;
	std::cout << "digit a word: ";
	std::cin  >> buff;
	std::cout << "you wrote: [\"" << buff << "\"]" << std::endl;
*/

	Trial a;
	a.foo = 10;	
	a.foofunct();
	return (0);
}
