/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 11:13:35 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/20 12:27:52 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <string>

// CONSTRUCTOR ----------------------------------------------------------------/

ClapTrap::ClapTrap(void) 
	: _name("default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) 
{
	if (DEBUG == 0)
		std::cout << "ClapTrap Basic constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) 
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) 
{
	if (DEBUG == 0)
		std::cout << "ClapTrap Named constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& obj) 
	: _name(obj._name), _hitPoints(obj._hitPoints), _energyPoints(obj._energyPoints),
	_attackDamage(obj._attackDamage) 
{
	if (DEBUG == 0)
		std::cout << "ClapTrap Copy constructor called" << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& obj)  
{
	if (this != &obj) {
		this->_name = obj._name;
		this->_hitPoints = obj._hitPoints;
		this->_energyPoints = obj._energyPoints;
		this->_attackDamage = obj._attackDamage;
	}
	if (DEBUG == 0)
		std::cout << "ClapTrap Assignment operator called" << std::endl;
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	if (DEBUG == 0)
		std::cout << "ClapTrap Destructor called" << std::endl;
}

// METHODS --------------------------------------------------------------------/

std::string	ClapTrap::getName(void) const
{
	return (_name);
}

void		ClapTrap::setName(std::string name)
{
	std::cout << "ClapTrap " << this->_name << " changes its name to: " ;
	this->_name = name;
	std::cout << this->_name << std::endl;
}

void		ClapTrap::attack(const std::string& target)
{
	if (_energyPoints > 0)
	{
		std::cout << "ClapTrap "	<< _name
				<< " attacks " 		<< target
				<< ", causing "		<< _attackDamage << " points of damage!"
				<< std::endl;
		_energyPoints--;
	}
	else {
		std::cout << "ClapTrap "		<< _name
				<< " cannot attack "	<< target
				<< " due to lack of energy resources, it might die trying!"
				<< std::endl;
	}
}

void		ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints > 0)
	{
		std::cout << "ClapTrap "	<< _name
				<< " recovered "	<< amount
				<< " repair points "
				<< std::endl;
		_energyPoints--;
		_hitPoints += amount;
	}
	else {
		std::cout << "ClapTrap "		<< _name
				<< " cannot recover"
				<< " due to lack of energy resources, it might die trying!"
				<< std::endl;
	}
}


void		ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints - amount > 0)
	{
		std::cout << "ClapTrap "	<< _name
				<< " has been hit and will loose "	<< amount
				<< " healt points "
				<< std::endl;
		_hitPoints -= amount;
	}
	else {
		std::cout << "ClapTrap "		<< _name
				<< " cannot recover due to lack of health it's unfortunatly dead!"
				<< std::endl;
		_hitPoints = 0;
	}
}

void		ClapTrap::setattackDamage(unsigned int amount)
{
	_attackDamage = amount;
	std::cout << "ClapTrap "		<< _name
			<< " level of attack damage set to: " << amount 
			<< " points" << std::endl;
}

int			ClapTrap::getAttackDamage(void) const
{
	return (_attackDamage);
}
