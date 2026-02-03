/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:56:40 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/03 13:27:28 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <locale>
#include <string>

std::string set_uppercase(const char *str)
{

	if (!str)
		return ("");

	std::locale		loc;
	std::string	strUpp(str);
	std::size_t	i = 0;
	while (i < strUpp.length())
	{
		strUpp[i] = std::toupper(strUpp[i], loc);
		i++;
	}
	return (strUpp);
}

int main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";

	for (int i = 1; i < ac; ++i){
		
		std::cout << set_uppercase(av[i]);
	}
	std::cout << std::endl;
}
