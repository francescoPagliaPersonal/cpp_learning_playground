/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 11:48:03 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/26 13:16:23 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_H
# define ICE_H

#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
	Ice(void);
	Ice(std::string const & type);
	Ice(const Ice& obj);
	Ice& operator=(const Ice& obj);
	~Ice(void);
	
	std::string const &	getType() const; //Returns the materia type
	virtual AMateria*	clone() const = 0;
	virtual void		use(ICharacter& target);

	protected:

	private:
	
};

#endif
