/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:15:17 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/04 14:13:16 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"
#include <cctype>
#include <locale>
#include <string>

int PhoneBook::ids = 0;

PhoneBook::PhoneBook(void) {}

PhoneBook::~PhoneBook(void) {}

static std::string format_string(std::string input)
{
	std::string	str(10, ' ');
	if (input.length() < 10)
		str.replace(10 - input.length(), input.length(), input);
	else {
		str.replace(0, 9, input, 0, 9);
		str.replace(9, 1, ".");
	}
	return (str); 
}


static bool not_ascii_input(const std::string& str)
{
	for (int i = 0; i < str.length(); ++i)
	{
		if (((unsigned char)(str[i]) & 0x80) != 0 
			|| ((unsigned char)(str[i]) & 0xE0) == 0)
			return (true);
	}
	return (false);
}

void	PhoneBook::display_table(const Contact *entry, int idsize) const
{
	std::string	str;

	std::cout << str.assign(45, '-') << '\n'
	<< "|  index   |   name   | surname  | nickname |\n"
	<< str << std::endl;
	if (!idsize)
	{
		std::cout << "|    Empty PhoneBook nothing to display     |\n"
				<< str << "\n "<< std::endl;
		return ;
	}
	for (int i = 0; i < idsize; i++) 
	{
		std::cout << "|" << str.assign(9, ' ') << (i + 1)
				<< "|" << format_string(entry[i].name)
				<< "|" << format_string(entry[i].surn)
				<< "|" << format_string(entry[i].nick) 
				<< "|" << std::endl;
	}
	std::cout << str.assign(45, '-') << std::endl;
	return ;
}

void	PhoneBook::display_contact(const Contact *entry, int id) const
{
	std::cout << "\n[ID: " << (id + 1) << "] contact details:\n"
			<< "name:         " << entry[id].name << "\n"
			<< "surname:      " << entry[id].surn << "\n"
			<< "nickname:     " << entry[id].nick << "\n"
			<< "phone nbr:    " << entry[id].phon << "\n"
			<< "dark secret:\n" << entry[id].secr << "\n" << std::endl;
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
	if (!idsize)
		return ;		
	i = 0;
	while (i < 3)
	{
		std::cout << "id: ";
		std::getline(std::cin, str);
		idlook = std::atoi(str.c_str()) - 1;
		// if id > available trow error and request a new one
		if (idlook >= idsize || idlook < 0)
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
	std::cout << "Editing contact id: " << (id + 1) << "/8"<< std::endl;
	std::cout << "name: " ;
	std::getline(std::cin, str);
	if (not_ascii_input(str))
		return (false);
	entry[id].name.assign(str);
	std::cout << "surname: ";
	std::getline(std::cin, str);
	if (not_ascii_input(str))
		return (false);
	entry[id].surn.assign(str);
	std::cout << "nick name: ";
	std::getline(std::cin, str);
	if (not_ascii_input(str))
		return (false);
	entry[id].nick.assign(str);
	std::cout << "phone number: ";
	std::getline(std::cin, str);
	if (not_ascii_input(str))
		return (false);
	entry[id].phon.assign(str);
	std::cout << "secret: ";
	std::getline(std::cin, str);
	if (not_ascii_input(str))
		return (false);
	entry[id].secr.assign(str);
	PhoneBook::ids += 1;
	return (true);
}

int	PhoneBook::getid(void) { return (PhoneBook::ids % 8); }

