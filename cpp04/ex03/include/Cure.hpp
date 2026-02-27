/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 12:55:41 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/27 18:04:47 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_H
# define CURE_H

#include "AMateria.hpp"
# include "debug.h"

class Cure : public AMateria
{
	public:
	Cure(void);
	Cure(const Cure& obj);
	Cure& operator=(const Cure& obj);
	~Cure(void);
	
	virtual AMateria*	clone() const;
	virtual void		use(ICharacter& target) const;

	protected:

	private:
	
};

#endif