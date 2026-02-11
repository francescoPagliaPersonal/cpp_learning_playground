/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 12:20:18 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/11 15:36:03 by fpaglia          ###   ########.fr       */
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
	for (int i = 0; i < LEV_MAX; ++i)
	{
		if (level == this->_complaints[i].key)
		{
			(this->*_complaints[i].f)();
			return ;
		}
	}
	std::cout << "STRANGE!!\nEventually I have nothing to complain about now...\n"
			<< "Till next time!" << std::endl;
	
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

 