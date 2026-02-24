/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 10:27:00 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/24 10:51:52 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

#include <iostream>
#include <string>

Animal::Animal(void) : _type("anybeast") 
{
	if (DEBUG == 0)
		std::cout << "Animal Basic constructor called" << std::endl;
}

Animal::Animal(std::string type) : _type(type) 
{
	if (DEBUG == 0)
		std::cout << "Animal Named constructor called" << std::endl;
}

Animal::Animal(const Animal& obj) : _type(obj._type)
{
	if (DEBUG == 0)
		std::cout << "Animal Copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& obj)
{
	if (this != &obj)
		_type = obj._type;
	if (DEBUG == 0)
		std::cout << "Animal = operator constructor called" << std::endl;
	return (*this);
}

Animal::~Animal(void)
{
	if (DEBUG == 0)
		std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType(void) const 
{
	return (_type);
}

void Animal::makeSound(void) const
{
	std::cout << "A generic animal doesn't emit specialize sound" << std::endl;
}
