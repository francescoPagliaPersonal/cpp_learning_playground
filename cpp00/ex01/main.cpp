/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 17:25:43 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/05 11:39:20 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"
#include <iostream>
#include <string>
#include "Errors.h"

static std::string	trim_string(std::string& str)
{
	const std::string	whitespace = " \t";

	size_t start = str.find_first_not_of(whitespace);
	size_t end = str.find_last_not_of(whitespace);
	if (start == str.npos)
		return ("");
	size_t range = end - start;
	return str.substr(start, range + 1);
}

int main()
{
	std::string input("Hello");
	PhoneBook	book;
	t_ret		ret;
	
	std::cout << "welcome to your Phone book, you have " << book.getid() 
			<< " contacts recorderd. \nPlease provide your command to start. \n" 
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
			ret = book.add();
			if (ret != OK)
				std::cout << error_messages[ret] << std::endl;
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

