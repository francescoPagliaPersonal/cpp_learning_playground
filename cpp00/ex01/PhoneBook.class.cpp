/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:15:17 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/05 11:46:19 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"
#include "Contact.class.hpp"

int PhoneBook::ids = 0;

PhoneBook::PhoneBook(void) {}

PhoneBook::~PhoneBook(void) {}

static std::string	trim_string(std::string& str)
{
	const std::string	whitespace = " \t";

	int start = str.find_first_not_of(whitespace);
	int end = str.find_last_not_of(whitespace);
	if (start == str.npos)
		return ("");
	int range = end - start;
	return str.substr(start, range + 1);
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
				<< "|" << format_string(entry[i].get_field(Contact::NAME))
				<< "|" << format_string(entry[i].get_field(Contact::SURNAME))
				<< "|" << format_string(entry[i].get_field(Contact::NICK))
				<< "|" << std::endl;
	}
	std::cout << str.assign(45, '-') << std::endl;
	return ;
}

void	PhoneBook::display_contact(const Contact *entry, int id) const
{
	std::cout << "\n[ID: " << (id + 1) << "] contact details:\n"
			<< "name:         " << entry[id].get_field(Contact::NAME) << "\n"
			<< "surname:      " << entry[id].get_field(Contact::SURNAME) << "\n"
			<< "nickname:     " << entry[id].get_field(Contact::NICK) << "\n"
			<< "phone nbr:    " << entry[id].get_field(Contact::PHONE) << "\n"
			<< "dark secret:\n" << entry[id].get_field(Contact::SECRET) << "\n" << std::endl;
	return ;
}

void	PhoneBook::search(void) const 
{
	std::string str;	
	int         idsize;
	int			idlook;
	int			i;

    idsize =  (PhoneBook::ids > 8) ? 8 : PhoneBook::ids;
	display_table(entry, idsize);
	if (!idsize)
		return ;		
	i = 0;
	while (i < 3)
	{
		std::cout << "id: ";
		std::getline(std::cin, str);
		idlook = std::atoi(str.c_str()) - 1;
		if (idlook >= idsize || idlook < 0)
			std::cout << "id not found" << std::endl;
		else {
			display_contact(entry, idlook);
			break ;
		}
		i++;
	}
	return ;
}

t_ret	PhoneBook::set_field(Contact& entry, enum Contact::e_fields id, std::string& str)
{
	t_ret	ret;
	std::string	trim_str;
	
	std::cout << entry.get_field_name(id)
			<< ": " ;
	if (!std::getline(std::cin, str))
	{
		std::cin.clear();
    	std::cout.flush();
		return (E_EOF);
	}
	trim_str = trim_string(str);
	if (not_ascii_input(trim_str))
		return (E_ASCII);
	ret = entry.set_field(id, trim_str);
		return (ret);
	return (OK);
}

t_ret	PhoneBook::add(void) 
{

	std::string str("");
	int id = PhoneBook::ids % 8;
	enum Contact::e_fields field_id = Contact::NAME;
	std::cout << "Editing contact id: " << (id + 1) << "/8"<< std::endl;
	for (int i = 0; i < Contact::MAX_FIELD; ++i)
	{
		t_ret	ret;
		field_id = static_cast<enum Contact::e_fields>(i);
		ret = set_field(entry[id], field_id,str);
		if (ret != OK)
			return (ret);
	}
	PhoneBook::ids += 1;
	return (OK);
}

int	PhoneBook::getid(void) { return (PhoneBook::ids % 8); }

