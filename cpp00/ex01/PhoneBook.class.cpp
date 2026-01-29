/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:15:17 by fpaglia           #+#    #+#             */
/*   Updated: 2026/01/29 18:59:24 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"
#include <cstdlib>

int PhoneBook::ids = 0;

PhoneBook::PhoneBook(void) {}

PhoneBook::~PhoneBook(void) {}

std::string format_string(std::string input)
{
	std::string	str(10, ' ');
	if (input.length() < 10)
		str.replace(10 - input.length(), input.length(), input);
	else {
		str.replace(0, 8, input);
		str.replace(9, 1, ".");
	}
	return (str); 
}

void display_table(const Contact *entry, int idsize)
{
	std::string	str;

	std::cout << str.assign(44, '-') << '\n'
	<< "|  index   |   name   | surname  | nickname |\n"
	<< str << std::endl;
	for (int i = 0; i < idsize; i++) 
	{
		std::cout << "|" << str.assign(9, ' ') << i
				<< "|" << format_string(entry[i].name)
				<< "|" << format_string(entry[i].surn)
				<< "|" << format_string(entry[i].nick) 
				<< "|" << std::endl;
	}
	return ;
}

void	display_contact(const Contact *entry, int id)
{
	std::cout << "here details of contact id: " << id << "\n"
			<< "name:      " << entry[id].name << "\n"
			<< "surname:   " << entry[id].surn << "\n"
			<< "nickname:  " << entry[id].nick << "\n"
			<< "phone nbr: " << entry[id].phon << "\n"
			<< "dark secret:\n " << entry[id].secr << std::endl;
	return ;
}

void	PhoneBook::search(void) const 
{
	std::string str;	
	int         idsize;
	int			idlook;
	int			i;

    idsize =  (PhoneBook::ids > 8) ? 8 : PhoneBook::ids;
	// display available contacts;
	display_table(entry, idsize);
	// offer cin to explore an id;
	i = 0;
	while (i < 3)
	{
		std::getline(std::cin, str);
		idlook = std::atoi(str.c_str());
		// if id > available trow error and request a new one
		if (idlook >= idsize)
			std::cout << "id not found" << std::endl;
		// else display detailed info
		else {
			display_contact(entry, idlook);
			break ;
		}
		i++;
	}
	return ;
}

bool	PhoneBook::add(void) 
{
	// prompt name of the field to fill up
	// offer cin to get data
	// continue till all the required fields are provided.
	std::string str;
	int id = PhoneBook::ids % 8;
	std::cout << "Add/replace contact id: " << id << std::endl;
	std::cout << "name: " ;
	std::getline(std::cin, str);
	entry[id].name.assign(str);
	std::cout << "surname: ";
	std::getline(std::cin, str);
	entry[id].surn.assign(str);
	std::cout << "nick name: ";
	std::getline(std::cin, str);
	entry[id].nick.assign(str);
	std::cout << "phone number: ";
	std::getline(std::cin, str);
	entry[id].phon.assign(str);
	std::cout << "secret: ";
	std::getline(std::cin, str);
	entry[id].secr.assign(str);
	PhoneBook::ids += 1;
	return (true);
}

int	PhoneBook::getid(void) { return (PhoneBook::ids % 8); }

