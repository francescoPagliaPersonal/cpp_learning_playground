/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:56:40 by fpaglia           #+#    #+#             */
/*   Updated: 2026/01/29 13:36:50 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

std::string set_uppercase(const char *str)
{

	if (!str)
		return ("");

	std::string strUpp(str);
	std::transform(strUpp.begin(), strUpp.end(), strUpp.begin(), (int(*)(int))std::toupper);
	return (strUpp);
}

int main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;

	for (int i = 1; i < ac; i++){
		
		std::cout << set_uppercase(av[i]);
	}
	std::cout << std::endl;
}
