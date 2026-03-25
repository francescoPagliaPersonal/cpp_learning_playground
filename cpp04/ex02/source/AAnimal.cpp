/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 13:44:22 by fpaglia           #+#    #+#             */
/*   Updated: 2026/03/24 17:08:24 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "AAnimal.hpp"


AAnimal::AAnimal(void) : _type("anybeast")
{
	if (DEBUG == 0)
		std::cout << "Animal Basic constructor called" << std::endl;
}

AAnimal::AAnimal(std::string type) : _type(type)
{
	if (DEBUG == 0)
		std::cout << "Animal Named constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& obj) : _type(obj._type)
{
	if (DEBUG == 0)
		std::cout << "Animal Copy constructor called" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& obj)
{
	if (this != &obj)
		_type = obj._type;
	if (DEBUG == 0)
		std::cout << "Animal = operator constructor called" << std::endl;
	return (*this);
}

AAnimal::~AAnimal(void)
{
	if (DEBUG == 0)
		std::cout << "Animal destructor called" << std::endl;
}

std::string AAnimal::getType(void) const 
{
	return (_type);
}
