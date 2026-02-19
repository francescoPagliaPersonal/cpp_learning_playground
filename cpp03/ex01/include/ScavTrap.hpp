
#ifndef SCAVTRAP_H
# define SCAVTRAP_H

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
	
	ScavTrap(void);
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap& obj);
	ScavTrap& operator=(const ScavTrap& obj);
	~ScavTrap(void);
	
	void			guardGate(void);
	
};

#endif

