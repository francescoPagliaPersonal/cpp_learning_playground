/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 10:27:00 by fpaglia           #+#    #+#             */
/*   Updated: 2026/03/24 17:27:44 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("wrongBeast") 
{
	if (DEBUG == 0)
		std::cout << "WrongAnimal Basic constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type) 
{
	if (DEBUG == 0)
		std::cout << "WrongAnimal Named constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& obj) : _type(obj._type)
{
	if (DEBUG == 0)
		std::cout << "WrongAnimal Copy constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& obj)
{
	if (this != &obj)
		_type = obj._type;
	if (DEBUG == 0)
		std::cout << "WrongAnimal = operator constructor called" << std::endl;
	return (*this);
}

WrongAnimal::~WrongAnimal(void)
{
	if (DEBUG == 0)
		std::cout << "WrongAnimal destructor called" << std::endl;
}

std::string WrongAnimal::getType(void) const 
{
	return (_type);
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "A generic animal doesn't emit specialize sound " 
				"especially when it's wrong!" << std::endl;
}
