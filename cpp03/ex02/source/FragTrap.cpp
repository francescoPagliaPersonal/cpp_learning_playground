/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 16:22:25 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/19 16:49:28 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ClapTrap.hpp"

// CONSTRUCTOR ----------------------------------------------------------------/

FragTrap::FragTrap(void) : ClapTrap() 
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;

	if (DEBUG == 0)
		std::cout << "FragTrap Basic constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;

	if (DEBUG == 0)
		std::cout << "FragTrap Named constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& obj) : ClapTrap(obj)
{
	if (DEBUG == 0)
		std::cout << "FragTrap Copy constructor called" << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap& obj)  
{
	if (this != &obj) 
		ClapTrap::operator=(obj);
	if (DEBUG == 0)
		std::cout << "FragTrap Assignment operator called" << std::endl;
	return (*this);
}

FragTrap::~FragTrap(void)
{
	if (DEBUG == 0)
		std::cout << "FragTrap Destructor called" << std::endl;
}

// METHODS --------------------------------------------------------------------/


void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->getName() << " is requesting a positive High Five" 
			<< std::endl;
}

void	FragTrap::attack(const std::string& target)
{
	if (_energyPoints > 0)
	{
		std::cout << "FragTrap "	<< _name
				<< " attacks " 		<< target
				<< ", causing "		<< _attackDamage << " points of damage!"
				<< std::endl;
		_energyPoints--;
	}
	else {
		std::cout << "FragTrap "		<< _name
				<< " cannot attack "	<< target
				<< " due to lack of energy resources, it might die trying!"
				<< std::endl;
	}
}

void		FragTrap::report(void)
{
	std::cout << "FragTrap " << _name
			<< "\thit point:    " << _hitPoints
			<< "\tattack point: " << _attackDamage
			<< "\tenergy point: " << _energyPoints
			<< std::endl;
}
