/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 17:10:50 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/27 17:51:50 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_H
# define MATERIASOURCE_H

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	public:

	MateriaSource(void);
	MateriaSource(const MateriaSource& obj);
	MateriaSource& operator=(const MateriaSource& obj);
	virtual ~MateriaSource(void);

	virtual void		learnMateria(AMateria*);
	virtual AMateria*	createMateria(std::string const & type);
	
	protected:
	AMateria*		_invetory[MAX_TEMPLATES];

};

#endif
