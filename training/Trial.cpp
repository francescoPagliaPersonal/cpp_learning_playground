/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Trial.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 09:52:04 by fpaglia           #+#    #+#             */
/*   Updated: 2026/01/28 11:17:36 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Trial.hpp"

Trial::Trial(void) {

	std::cout << "Constructor called" << std::endl;
	this->foo = 84;
	this->foofunct();
	return ;
}

Trial::~Trial(void) {

	std::cout << "Destructor called" << std::endl;
	return ;
}

void	Trial::foofunct(void) {

	std::cout <<	"writing from a member function\nmy foo values is: " 
		<< this->foo << std::endl;
	return ;
}
