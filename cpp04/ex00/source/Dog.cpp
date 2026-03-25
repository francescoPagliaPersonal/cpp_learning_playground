/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 10:27:06 by fpaglia           #+#    #+#             */
/*   Updated: 2026/03/24 17:27:25 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal() 
{
	_type = "Dog";
	if (DEBUG == 0)
		std::cout << "Dog Basic constructor called" << std::endl;
}

Dog::Dog(const Dog& obj) : Animal()
{
	_type = obj._type;
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
	if (DEBUG == 0)
		std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << "WOFF WOFF!!" << std::endl;
}
