/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 12:20:18 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/10 15:28:54 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void) {}
Harl::~Harl(void) {}

void	Harl::complain(std::string level)
{
		std::cout << "WHY ARE YOU BOTHERING MEE!!!" << std::endl;
}

void	Harl::_debug(void) {
	std::cout << "I love having extra bacon for my 7XL-double-cheese"
			<< "-triple-pickle-special-ketchup burger.\n I really do!" << std::endl;
}

void	Harl::_info(void) {
	std::cout << "I cannot believe adding extra bacon costs more money.\n"
			<< "You didn’t put enough bacon in my burger!\n"
			<< "If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::_warning(void) {
	std::cout << "I think I deserve to have some extra bacon for free." 
			<< "I’ve been coming for years, whereas you started working "
			<< "here just last month." << std::endl;
}

void	Harl::_error(void) {
	std::cout << "This is unacceptable! I want to speak to the manager now."
			<< std::endl;
}

