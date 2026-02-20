/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 11:13:52 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/20 12:27:37 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
# define CLAPTRAP_H

# ifndef DEBUG
#  define DEBUG 0
# endif

# include <string>
# include <iostream>

class ClapTrap 
{
	public:
	
	ClapTrap(void);
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap& obj);
	ClapTrap& operator=(const ClapTrap& obj);
	~ClapTrap(void);
	
	void			attack(const std::string& target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);
	
	void			setattackDamage(unsigned int amount);
	int				getAttackDamage(void) const;
	
	std::string		getName(void) const;
	void			setName(std::string name);
	
	protected:
	
	std::string		_name;
	int				_hitPoints; 	
	int				_energyPoints; 	
	int				_attackDamage; 	
	
};

#endif

