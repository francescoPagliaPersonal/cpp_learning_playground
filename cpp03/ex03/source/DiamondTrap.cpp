/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 17:03:26 by fpaglia           #+#    #+#             */
/*   Updated: 2026/03/10 15:04:54 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

DiamondTrap::DiamondTrap(void)
	: ClapTrap("default_clap_name"), FragTrap(), ScavTrap(), _name("default")
{
	/* Interesting point of discussion about attribute values
	 * 
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	*/
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 30;
	
	if (DEBUG == 0)
		std::cout << "DiamondTrap Basic constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(name + "_clap_name"), FragTrap(), ScavTrap(), _name(name) 
{
	/* Interesting point of discussion about attribute values
	 * 
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	*/
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 30;
		
	if (DEBUG == 0)
		std::cout << "DiamondTrap Named constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& obj) 
	: ClapTrap(obj), FragTrap(obj), ScavTrap(obj)
{
	_name = obj._name;
	_hitPoints = obj._hitPoints;
	_energyPoints = obj._energyPoints;
	_attackDamage = obj._attackDamage;
	if (DEBUG == 0)
		std::cout << "DiamondTrap Copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& obj)
{
	if (this != &obj) {
		ClapTrap::operator=(obj);
		_name = obj._name;
		_hitPoints = obj._hitPoints;
		_energyPoints = obj._energyPoints;
		_attackDamage = obj._attackDamage;
	}
	if (DEBUG == 0)
		std::cout << "DiamondTrap Assignment operator called" << std::endl;
	return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
	if (DEBUG == 0)
		std::cout << "DiamondTrap Destructor called" << std::endl;
}

void	DiamondTrap::whoAmI(void) 
{
	std::cout << "DiamondTrap obj_name: " << _name
			<< "\tshadowed name: " << ClapTrap::_name
			<< std::endl;  
}

void		DiamondTrap::report(void) const
{
	std::cout << "DiamTrap " << _name
			<< "\thit point:    " << _hitPoints
			<< "  \tenergy point: " << _energyPoints
			<< "\tattack point: " << _attackDamage
			<< std::endl;
}
