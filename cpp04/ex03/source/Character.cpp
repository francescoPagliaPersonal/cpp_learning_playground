/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 14:56:57 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/27 18:26:22 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"

// CONSTRUCTORS ---------------------------------------------------------------/

Character::Character(void) : _name("default") 
{
	for (int i = 0; i < MAX_ITEMS; ++i)
		_invetory[i] = NULL;
}

Character::Character(std::string const & name) : _name(name)
{
	for (int i = 0; i < MAX_ITEMS; ++i)
		_invetory[i] = NULL;
}

Character::Character(const Character& obj) : _name(obj._name) 
{
	for (int i = 0; i < MAX_ITEMS; ++i)
	{
		if (obj._invetory[i] != NULL)
			_invetory[i] = obj._invetory[i]->clone();
	}
		
}

Character::~Character(void) 
{
	for (int i = 0; i < MAX_ITEMS; ++i)
	{
		delete _invetory[i];
	}
}

Character& Character::operator=(const Character& obj)
{
	if (this == &obj)
		return (*this);
	_name = obj._name;
	for (int i = 0; i < MAX_ITEMS; ++i)
	{
		if (obj._invetory[i] != NULL)
			_invetory[i] = obj._invetory[i]->clone();
	}
	return (*this);
}

// CONSTRUCTORS ---------------------------------------------------------------/


ICharacter*	Character::clone() const
{
	return (new Character(*this));
}

void	Character::equip(AMateria* m)
{
	for (int i = 0; i < MAX_ITEMS; ++i)
	{
		if (_invetory[i] == NULL)
		{
			_invetory[i] = m;
			break;
		}
	}
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx < MAX_ITEMS)
		_invetory[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < MAX_ITEMS && _invetory[idx] != NULL)
	{
		_invetory[idx]->use(target);
		_invetory[idx] = NULL;
	}
}

void	Character::report() const
{
	std::cout << "Items collected by: " << this->_name << "\n";
	for (int i = 0; i < MAX_ITEMS; ++i)
	{
		if (_invetory[i] != NULL)
			std::cout << "item " << i << " : " << _invetory[i]->getType() << "  " ;
		else 
			std::cout << "item " << i << " : " << "NULL" << "  " ;
			
	}
	std::cout << "\n	" << std::endl;
}
