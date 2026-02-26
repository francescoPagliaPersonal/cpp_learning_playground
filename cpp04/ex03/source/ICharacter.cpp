/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 14:56:57 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/26 16:51:05 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"

ICharacter::ICharacter(void) : _name ("default") 
{
	for (int i = 0; i < 4; ++i)
	_invetory[i] = NULL;
}

ICharacter::ICharacter(std::string const & name) : _name(name)
{
	for (int i = 0; i < 4; ++i)
	_invetory[i] = NULL;
}


ICharacter::ICharacter(const ICharacter& obj) : _name(obj._name) 
{
	for (int i = 0; i < 4; ++i)
		_invetory[i] = NULL;
}

ICharacter::~ICharacter(void) {}

ICharacter& ICharacter::operator=(const ICharacter& obj)
{
	if (this != &obj)
	{
		_name = obj._name;
		for (int i = 0; i < 4; ++i)
			_invetory[i] = NULL;
	}
	return (*this);
}

std::string const & ICharacter::getName() const
{
	return (_name);
}