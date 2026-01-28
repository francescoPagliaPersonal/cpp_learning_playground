/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 17:26:37 by fpaglia           #+#    #+#             */
/*   Updated: 2026/01/28 11:58:04 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Trial.class.hpp"
#include "InitLst.class.hpp"

int main(void) {
/*	char buff[512];

	std::cout << "Hello World" << std::endl;
	std::cout << "digit a word: ";
	std::cin  >> buff;
	std::cout << "you wrote: [\"" << buff << "\"]" << std::endl;
*/

/*	Trial a;
	a.foo = 10;
	Trial b;	
	a.foofunct();
	b.foofunct();
	std::cout << "value of sum b: " << b.sum(10,5) << std::endl;
*/
	InitLst lst(1, 'p', 1.5);
	lst.report();
	return (0);
}
