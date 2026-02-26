/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 14:56:57 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/26 17:06:05 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"

Character::Character(void) : ICharacter("default") 
{
	for (int i = 0; i < 4; ++i)
		_invetory[i] = NULL;
}

Character::Character(std::string const & name) : ICharacter(name)
{
	for (int i = 0; i < 4; ++i)
		_invetory[i] = NULL;
}

Character::Character(const Character& obj) : ICharacter(obj._name) 
{
	for (int i = 0; i < 4; ++i)
		_invetory[i] = NULL;
}

Character::~Character(void) {}

Character& Character::operator=(const Character& obj)
{
	if (this != &obj)
		_name = obj._name;
	return (*this);
}

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
	if (idx >= MAX_ITEMS)
		return ;
	_invetory[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx <= MAX_ITEMS && _invetory[idx] != NULL)
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
