/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:13:23 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/27 17:53:27 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_H
# define  CHARACTER_H

#include <string>
# include "debug.h"
#include "ICharacter.hpp"


class Character : public ICharacter
{
	public:
	
	Character(void);
	Character(std::string const & name);
	Character(const Character& obj);
	Character& operator=(const Character& obj);
	virtual ~Character(void);
	
	virtual ICharacter*			clone() const;
	virtual std::string const &	getName() const;
	
	
	virtual void		equip(AMateria* m);
	virtual void		unequip(int idx);
	virtual void		use(int idx, ICharacter& target);
	
	virtual void		report() const;

	
	private:

	std::string		_name;
	AMateria*		_invetory[MAX_ITEMS];
	
};

#endif