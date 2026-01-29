/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 17:25:43 by fpaglia           #+#    #+#             */
/*   Updated: 2026/01/29 18:07:55 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"
#include <iostream>
#include <string>

int main()
{
	std::string input("Hello");
	PhoneBook	book;
	std::cout << "welcome to your Phone book, you have " << book.getid() 
			<< " recorderd. \n Please provide your command to start. \n \
				use \nADD to add a new contact\nSEARCH to display a \
				recorded contact." 
			<< std::endl;

	while (!input.compare("EXIT"))
	{
		std::getline(std::cin, input);
		if (input.compare("ADD"))
			book.add();
		else if (input.compare("SEARCH"))
			book.search();
		else
			std::cout << "Command not found." << std::endl;
	}
	return (0);
}
