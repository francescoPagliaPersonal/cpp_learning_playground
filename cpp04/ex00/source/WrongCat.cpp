/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 10:27:12 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/26 10:18:40 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

#include <iostream>
#include <string>

WrongCat::WrongCat(void) : WrongAnimal(), _type("wrongCat") 
{
	if (DEBUG == 0)
		std::cout << "WrongCat Basic constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& obj) : WrongAnimal(), _type(obj._type)
{
	if (DEBUG == 0)
		std::cout << "WrongCat Copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& obj)
{
	if (this != &obj)
		_type = obj._type;
	if (DEBUG == 0)
		std::cout << "WrongCat = operator constructor called" << std::endl;
	return (*this);
}

WrongCat::~WrongCat(void)
{
	if (DEBUG == 0)
		std::cout << "WrongCat destructor called" << std::endl;
}

std::string WrongCat::getType(void) const 
{
	return (_type);
}

void WrongCat::makeSound(void) const
{
	std::cout << "WROONGMIAOOOO!!" << std::endl;
}
