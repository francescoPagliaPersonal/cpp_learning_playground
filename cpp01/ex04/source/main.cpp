/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 10:53:24 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/11 17:01:22 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Looser.hpp"
#include <iostream>
#include <ostream>

int main(int ac, char **av)
{
	if (ac < 4 || ac > 5) {
		std::cerr << "Wrong number of parameters.\n"
				<< "Please use the following Syntax: \n\n\t$>" 
				<< av[0] << " {input filename} {patter to replace} "
				<< "{substitution string} [[{output filename} (optional)]]" 
				<< ""<< std::endl;
		return (1);
	}
	if (ac == 4)
	{
		Looser myaction(av[1], av[2], av[3]);
		if (!myaction.replace())
			std::clog << "Error opening files" << std::endl; 
		else
		 	std::clog << myaction.get_output_filename() << " has been created."
					<< std::endl;
	}
	else
	{
		Looser myaction(av[1], av[2], av[3], av[4]);
		if (!myaction.replace())
			std::clog << "Error opening files" << std::endl; 
		else
		 	std::clog << myaction.get_output_filename() << " has been created."
					<< std::endl;
	}
	return (0);
}
