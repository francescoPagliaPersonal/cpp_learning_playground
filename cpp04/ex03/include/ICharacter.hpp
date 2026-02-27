/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 11:43:57 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/27 17:50:29 by fpaglia          ###   ########.fr       */
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
	
	virtual ~ICharacter(void);
	
	virtual ICharacter*			clone() const = 0;
	
	virtual std::string const &	getName() const = 0;
	
	virtual void		equip(AMateria* m) = 0;
	virtual void		unequip(int idx) = 0;
	virtual void		use(int idx, ICharacter& target) = 0;
	
	virtual void		report() const = 0;
	
};

#endif
