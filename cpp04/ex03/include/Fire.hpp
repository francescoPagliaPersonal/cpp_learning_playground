/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fire.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 11:48:03 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/27 17:56:37 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIRE_H
# define FIRE_H

#include "AMateria.hpp"
# include "debug.h"

class Fire : public AMateria
{
	public:
	Fire(void);
	Fire(const Fire& obj);
	Fire& operator=(const Fire& obj);
	~Fire(void);
	
	virtual AMateria*	clone() const;
	virtual void		use(ICharacter& target) const;

	protected:

	private:
	
};

#endif
