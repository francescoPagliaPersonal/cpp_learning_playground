/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 17:25:43 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/04 14:20:46 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"
#include <iostream>
#include <string>

std::string	trim_string(std::string& str)
{
	const std::string	whitespace = " \t";

	int start = str.find_first_not_of(whitespace);
	int end = str.find_last_not_of(whitespace);
	if (start == std::string::npos)
		return ("");
	int range = end - start;
	return str.substr(start, range + 1);
}

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
		if (!std::getline(std::cin, input))
			break ;
		input.assign(trim_string(input));
		if (input.compare("ADD") == 0)
		{
			if (book.add() == false)
				std::cout << "Non ascii character added, operation aborted" << std::endl;
		}
		else if (input.compare("SEARCH") == 0)
			book.search();
		else if (input.compare("EXIT") != 0)
			std::cout << "Command not found." << std::endl;
	}
	std::cin.clear();
    std::cout.flush();
	return (0);
}

