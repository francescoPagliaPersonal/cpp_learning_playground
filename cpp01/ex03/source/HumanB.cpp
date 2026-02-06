/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 23:03:48 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/06 23:03:49 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>
#include <iterator>

HumanB::HumanB(std::string name) : name(name), weapon(NULL) {};

HumanB::~HumanB(void) {};

void	HumanB::attack(void) const
{
	if (!weapon)
		std::cout << name << " is with his own bare hands";
	else
		std::cout << name << " attacks with their "<< weapon->getType();
	std::cout << std::endl;
}

void	HumanB::setWeapon(Weapon& myWeapon)
{
	this->weapon = &myWeapon;
}
