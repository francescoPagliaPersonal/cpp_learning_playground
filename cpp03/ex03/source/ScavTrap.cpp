/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 16:22:25 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/19 16:53:10 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

// CONSTRUCTOR ----------------------------------------------------------------/

ScavTrap::ScavTrap(void) : ClapTrap() 
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;

	if (DEBUG == 0)
		std::cout << "ScavTrap Basic constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;

	if (DEBUG == 0)
		std::cout << "ScavTrap Named constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& obj) : ClapTrap(obj)
{
	if (DEBUG == 0)
		std::cout << "ScavTrap Copy constructor called" << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& obj)  
{
	if (this != &obj) 
		ClapTrap::operator=(obj);
	if (DEBUG == 0)
		std::cout << "ScavTrap Assignment operator called" << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	if (DEBUG == 0)
		std::cout << "ScavTrap Destructor called" << std::endl;
}

// METHODS --------------------------------------------------------------------/


void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->getName() << " is now in Gate keeper mode" 
			<< std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (_energyPoints > 0)
	{
		std::cout << "ScavTrap "	<< _name
				<< " attacks " 		<< target
				<< ", causing "		<< _attackDamage << " points of damage!"
				<< std::endl;
		_energyPoints--;
	}
	else {
		std::cout << "ScavTrap "		<< _name
				<< " cannot attack "	<< target
				<< " due to lack of energy resources, it might die trying!"
				<< std::endl;
	}
}

void		ScavTrap::report(void)
{
	std::cout << "ScavTrap " << _name
			<< "\thit point:    " << _hitPoints
			<< "\tenergy point: " << _energyPoints
			<< "\tattack point: " << _attackDamage
			<< std::endl;
}
