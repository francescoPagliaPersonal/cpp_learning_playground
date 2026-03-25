/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 10:27:12 by fpaglia           #+#    #+#             */
/*   Updated: 2026/03/24 17:25:07 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat(void) : Animal()
{
	_type = "Cat";
	ideas = new Brain();
	if (DEBUG == 0)
		std::cout << "Cat Basic constructor called" << std::endl;
}

Cat::Cat(const Cat& obj) : Animal()
{
	_type = obj._type;
	ideas = new Brain(*obj.ideas);
	if (DEBUG == 0)
		std::cout << "Cat Copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& obj)
{
	if (this != &obj)
	{
		_type = obj._type;
		*ideas = *obj.ideas;
	}
	if (DEBUG == 0)
		std::cout << "Cat = operator constructor called" << std::endl;
	return (*this);
}

Cat::~Cat(void)
{
	delete ideas;
	if (DEBUG == 0)
		std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound(void) const
{
	std::cout << "MIAOOOO!!" << std::endl;
}

bool	Cat::changeIdea(unsigned int id, std::string idea)
{
	if (id < MAX_STRINGS)
	{
		ideas->setAnIdea(id, idea);
		return (true);
	}
	return false;	
}

const std::string&	Cat::getIdea(unsigned int id) const
{
	return (ideas->getAnIdea(id));
}