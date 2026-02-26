/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 11:48:03 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/26 16:31:12 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_H
# define ICE_H

#include "AMateria.hpp"
# include "debug.h"

class Ice : public AMateria
{
	public:
	Ice(void);
	Ice(const Ice& obj);
	Ice& operator=(const Ice& obj);
	~Ice(void);
	
	virtual AMateria*	clone() const;
	virtual void		use(ICharacter& target) const;

	protected:

	private:
	
};

#endif
