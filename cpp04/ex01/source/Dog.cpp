/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 10:27:06 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/24 14:23:37 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

#include <iostream>
#include <string>

Dog::Dog(void) : Animal(), _type("Dog") 
{
	ideas = new Brain();
	if (DEBUG == 0)
		std::cout << "Dog Basic constructor called" << std::endl;
}

Dog::Dog(const Dog& obj) : Animal(), _type(obj._type)
{
	ideas = new Brain; // FIXME ... what is the meaning of generating a new brain when I should copy over from a different one?
	if (DEBUG == 0)
		std::cout << "Dog Copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& obj)
{
	if (this != &obj)
		_type = obj._type;
	if (DEBUG == 0)
		std::cout << "Dog = operator constructor called" << std::endl;
	return (*this);
}

Dog::~Dog(void)
{
	delete ideas;
	if (DEBUG == 0)
		std::cout << "Dog destructor called" << std::endl;
}

std::string Dog::getType(void) const 
{
	return (_type);
}

void Dog::makeSound(void) const
{
	std::cout << "WOFF WOFF!!" << std::endl;
}
