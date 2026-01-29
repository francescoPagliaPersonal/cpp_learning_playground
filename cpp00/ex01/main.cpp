/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 17:25:43 by fpaglia           #+#    #+#             */
/*   Updated: 2026/01/29 23:39:05 by fpaglia          ###   ########.fr       */
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
			<< " recorderd. \nPlease provide your command to start. \n" 
			<< "use: \n\t- ADD to add a new contact\n\t- SEARCH to display a "
			<< "recorded contact.\n"
			<< std::endl;

	while (input.compare("EXIT"))
	{
		std::cout << "> ";
		std::getline(std::cin, input);
		if (input.compare("ADD") == 0)
			book.add();
		else if (input.compare("SEARCH") == 0)
			book.search();
		else if (input.compare("EXIT") != 0)
			std::cout << "Command not found." << std::endl;
	}
	return (0);
}
