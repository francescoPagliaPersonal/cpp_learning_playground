/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:56:40 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/04 13:25:59 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	is_ascii_input(const char *str)
{
	while (*str)
	{
		if (((unsigned char)(*str) & 0x80) != 0 
			|| ((unsigned char)(*str) & 0xE0) == 0)
			return (0);
		str++;
	}
	return (1);
}

std::string set_uppercase(const char *str)
{

	if (!str)
		return ("");

	std::locale		loc("");
	std::string		strUpp(str);
	std::size_t		i = 0;
	while (i < strUpp.length())
	{
		strUpp[i] = std::toupper(strUpp[i], loc);
		i++;
	}
	return (strUpp);
}


int main(int ac, char **av)
{
	if (ac == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	
	std::string str;

	for (int i = 1; i < ac; ++i)
	{
		if (is_ascii_input(av[i]))
			str += set_uppercase(av[i]);
		else
		{
			std::cout << "please provide string of ascii characters only" << std::endl;
			return (1);
		}
	}
	std::cout << str << std::endl;
}
