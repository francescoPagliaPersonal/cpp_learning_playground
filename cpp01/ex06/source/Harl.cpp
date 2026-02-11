/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 12:20:18 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/11 16:10:22 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void) {
	_complaints[DEBUG].key = "DEBUG";
	_complaints[DEBUG].f = &Harl::_debug;
	_complaints[INFO].key = "INFO";
	_complaints[INFO].f = &Harl::_info;
	_complaints[WARNING].key = "WARNING";
	_complaints[WARNING].f = &Harl::_warning;
	_complaints[ERROR].key = "ERROR";
	_complaints[ERROR].f = &Harl::_error;
}

Harl::~Harl(void) {}

void	Harl::complain(std::string level)
{
	int i;
	for (i = 0; i < LEV_MAX; ++i)
	{
		if (level == this->_complaints[i].key)
			break ;
	}
	switch (i)
	{
		case 0:
			std::cout << "[ " << this->_complaints[0].key << " ]\n";
			(this->*_complaints[0].f)();
			std::cout << std::endl;
		case 1:
			std::cout << "[ " << this->_complaints[1].key << " ]\n";
			(this->*_complaints[1].f)();
			std::cout << std::endl;
		case 2:
			std::cout << "[ " << this->_complaints[2].key << " ]\n";
			(this->*_complaints[2].f)();
			std::cout << std::endl;
		case 3:
			std::cout << "[ " << this->_complaints[3].key << " ]\n";
			(this->*_complaints[3].f)();
			std::cout << std::endl;
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problem ]" << std::endl;
		
	}
	
}

void	Harl::_debug(void) {
	std::cout << "I love having extra bacon for my 7XL-double-cheese"
			<< "-triple-pickle-special-ketchup burger.\nI really do!" << std::endl;
}

void	Harl::_info(void) {
	std::cout << "I cannot believe adding extra bacon costs more money.\n"
			<< "You didn’t put enough bacon in my burger!\n"
			<< "If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::_warning(void) {
	std::cout << "I think I deserve to have some extra bacon for free.\n" 
			<< "I’ve been coming for years, whereas you started working "
			<< "here just last month." << std::endl;
}

void	Harl::_error(void) {
	std::cout << "This is unacceptable! I want to speak to the manager now."
			<< std::endl;
}

 