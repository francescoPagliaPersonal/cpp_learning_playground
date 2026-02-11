/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 12:20:01 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/11 15:41:02 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

std::string set_uppercase(const std::string& str)
{

	if (str.length() == 0)
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
	Harl myHarl;
	std::string complaint("");
	
	if (ac != 2)
	{
		std::clog << "Wrong number of parameter.\nPlease use:\t" << av[0]
				<< "{complain level[DEBUG, INFO, WARNING, ERROR]}" << std::endl;
		return (1);
	}
	complaint = av[1];
	myHarl.complain(complaint);
	return (0);
}
