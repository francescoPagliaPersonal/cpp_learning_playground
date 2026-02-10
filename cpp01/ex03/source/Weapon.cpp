/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 23:15:11 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/10 10:16:54 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string wtype) : _type(wtype) {}

Weapon::~Weapon(void) {}

void	Weapon::setType(std::string name) 
{
	this->_type = name;
}

const std::string&	Weapon::getType(void) const
{
	return (this->_type);
}