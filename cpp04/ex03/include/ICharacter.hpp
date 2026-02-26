/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 11:43:57 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/26 16:52:04 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_H
# define ICHARACTER_H

# define MAX_ITEMS 4

# include <string>
# include "debug.h"

class AMateria;

class ICharacter
{
	public:
	ICharacter(void);
	ICharacter(std::string const & name);
	ICharacter(const ICharacter& obj);
	ICharacter& operator=(const ICharacter& obj);
	virtual ~ICharacter(void);

	virtual std::string const &	getName() const;
	virtual void 				equip(AMateria* m) = 0;
	virtual void				unequip(int idx) = 0;
	virtual void 				use(int idx, ICharacter& target) = 0;
	virtual ICharacter*			clone() const = 0;
	virtual void				report() const = 0;
	
	protected:

	std::string		_name;
	AMateria*		_invetory[MAX_ITEMS];
};

#endif
