/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 23:03:48 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/10 10:16:50 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>
#include <iterator>

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {};

HumanB::~HumanB(void) {};

void	HumanB::attack(void) const
{
	if (!_weapon)
		std::cout << _name << " is with his own bare hands";
	else
		std::cout << _name << " attacks with their "<< _weapon->getType();
	std::cout << std::endl;
}

void	HumanB::setWeapon(Weapon& myWeapon)
{
	this->_weapon = &myWeapon;
}
