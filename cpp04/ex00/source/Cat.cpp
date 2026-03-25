/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 10:27:12 by fpaglia           #+#    #+#             */
/*   Updated: 2026/03/24 17:26:54 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
	_type = "Cat";
	if (DEBUG == 0)
		std::cout << "Cat Basic constructor called" << std::endl;
}

Cat::Cat(const Cat& obj) : Animal()
{
	_type = obj._type;
	if (DEBUG == 0)
		std::cout << "Cat Copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& obj)
{
	if (this != &obj)
		_type = obj._type;
	if (DEBUG == 0)
		std::cout << "Cat = operator constructor called" << std::endl;
	return (*this);
}

Cat::~Cat(void)
{
	if (DEBUG == 0)
		std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound(void) const
{
	std::cout << "MIAOOOO!!" << std::endl;
}
