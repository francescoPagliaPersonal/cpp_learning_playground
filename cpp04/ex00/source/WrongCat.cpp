/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 10:27:12 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/24 11:22:07 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

#include <iostream>
#include <string>

WrongCat::WrongCat(void) : WrongAnimal(), _type("Cat") 
{
	if (DEBUG == 0)
		std::cout << "Cat Basic constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& obj) : WrongAnimal(), _type(obj._type)
{
	if (DEBUG == 0)
		std::cout << "Cat Copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& obj)
{
	if (this != &obj)
		_type = obj._type;
	if (DEBUG == 0)
		std::cout << "Cat = operator constructor called" << std::endl;
	return (*this);
}

WrongCat::~WrongCat(void)
{
	if (DEBUG == 0)
		std::cout << "Cat destructor called" << std::endl;
}

std::string WrongCat::getType(void) const 
{
	return (_type);
}

void WrongCat::makeSound(void) const
{
	std::cout << "MIAOOOO!!" << std::endl;
}
