#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

// CONSTRUCTOR ----------------------------------------------------------------/

ScavTrap::ScavTrap(void) : ClapTrap() {
	if (DEBUG == 0)
		std::cout << "ScavTrap Basic constructor called" << std::endl;
}
/*

	: _name("default"), _hitPoints(100), _energyPoints(50), _attackDamage(20) 
{
	if (DEBUG == 0)
		std::cout << "ScavTrap Basic constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) 
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) 
{
	if (DEBUG == 0)
		std::cout << "ScavTrap Named constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& obj) 
	: _name(obj._name), _hitPoints(obj._hitPoints), _energyPoints(obj._energyPoints),
	_attackDamage(obj._attackDamage) 
{
	if (DEBUG == 0)
		std::cout << "ScavTrap Copy constructor called" << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& obj)  
{
	if (this != &obj) {
		this->_name = obj._name;
		this->_hitPoints = obj._hitPoints;
		this->_energyPoints = obj._energyPoints;
		this->_attackDamage = obj._attackDamage;
	}
	if (DEBUG == 0)
		std::cout << "ScavTrap Assignment operator called" << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	if (DEBUG == 0)
		std::cout << "ScavTrap Destructor called" << std::endl;
}

*/

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->getName() << "is now in Gate keeper mode" 
			<< std::endl;
}