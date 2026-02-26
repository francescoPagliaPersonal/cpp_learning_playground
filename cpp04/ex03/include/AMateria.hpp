/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 11:38:41 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/26 13:32:16 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_H
# define AMATERIA_H

# include <string>

class ICharacter;

class AMateria 
{
	public:
	AMateria(void);
	AMateria(std::string const & type);
	AMateria(const AMateria& obj);
	AMateria& operator=(const AMateria& obj);
	virtual ~AMateria(void);
	
	virtual std::string const &	getType(void) const; //Returns the materia type
	virtual AMateria*	clone(void) const = 0;
	virtual void		use(ICharacter& target);

	protected:
	
	std::string			_type;
};

#endif
