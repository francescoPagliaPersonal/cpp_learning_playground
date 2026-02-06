/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 21:36:38 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/06 21:36:46 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
	std::string myStr("HI THIS IS BRAIN");
	std::string *stringPTR;
	std::string& stringREF = myStr;

	stringPTR = &myStr;
	std::cout	<< "address:\tmyStr\t\t" <<  &myStr << '\n'
				<< "address:\tstringPTR\t" << stringPTR << '\n'
				<<  "address:\tstringREF\t" << &stringREF << '\n'
				<< std::endl;

	std::cout	<< "value:\t\tmyStr\t\t" <<  myStr << '\n'
				<< "value:\t\tstringPTR\t" << *stringPTR << '\n'
				<<  "value:\t\tstringREF\t" << stringREF << '\n'
				<< std::endl;
}