/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 11:43:57 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/26 13:20:17 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_H
# define ICHARACTER_H

# include <string>

class AMateria;

class ICharacter
{
	public:
	ICharacter(void);
	ICharacter(std::string const & type);
	ICharacter(const ICharacter& obj);
	ICharacter& operator=(const ICharacter& obj);
	virtual ~ICharacter(void);

	virtual std::string const &	getName() const = 0;
	virtual void 				equip(AMateria* m) = 0;
	virtual void				unequip(int idx) = 0;
	virtual void 				use(int idx, ICharacter& target) = 0;
	
	private:

	std::string		_name;
	AMateria*		_invetory[4];
};

#endif
