/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 11:38:41 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/27 18:01:22 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_H
# define AMATERIA_H

# include <string>
# include <iostream>
# include "debug.h"

class ICharacter;

class AMateria 
{
	public:
	AMateria(void);
	AMateria(std::string const & type);
	AMateria(const AMateria& obj);
	AMateria& operator=(const AMateria& obj);
	virtual ~AMateria(void);
	
	virtual std::string const &	getType(void) const;
	virtual AMateria*	clone(void) const = 0;
	virtual void		use(ICharacter& target) const = 0;

	protected:
	
	std::string			_type;
};

#endif
