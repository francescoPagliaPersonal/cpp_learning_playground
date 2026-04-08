/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 15:06:38 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/08 12:08:59 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <exception>
#include <istream>
#include <ostream>
#include <sstream>
#include <string>

# define MAXBUR 5

int main()
{
	std::cout << "\n\n-------BUILDING BUREAUCRATS --------\n" << std::endl;
			
	Bureaucrat *sad[MAXBUR];
	for (int i = 0; i < MAXBUR; ++i) {
				
		try {
			std::stringstream burName;
			burName << "Bob_" << i;
			sad[i] = new Bureaucrat(burName.str(), i * 50);	
			std::cout << *sad[i] << std::endl;		
		}
		catch (std::exception& e){
			sad[i] = NULL;
			std::cout << "ERROR:  " << "Bob_" << i << " not created: "
			<< e.what() << std::endl;
		}
	}
	
	std::cout << "\n\n-------INCREMENT  --------\n" << std::endl;

	while (sad[1]->getGrade() >= 1) {
		try {
			sad[1]->increment(20);
			std::cout << "INCREMENT: " << *sad[1] << std::endl;
		}
		catch (std::exception& e) {
			std::cout << "ERROR: " << sad[1]->getName() << " "
					<< e.what() << " (wanted " << sad[1]->getGrade() - 20
					<< ")"  << std::endl;
			break ;
		}
	}

	std::cout << "\n\n------- DECREMENT --------\n" << std::endl;
	
	while (sad[1]->getGrade() <= 150) {
		try {
			sad[1]->decrement(20);
			std::cout << "DECREMENT: " << *sad[1] << std::endl;
		}
		catch (std::exception& e) {
			std::cout << "ERROR: " << sad[1]->getName() << " "
					<< e.what() << " (wanted " << sad[1]->getGrade() + 20
					<< ")"  << std::endl;
			break ;
		}
	}

	for (int i = 0; i < MAXBUR; ++i) {
		if (sad[i])
			delete sad[i];
	}

}
