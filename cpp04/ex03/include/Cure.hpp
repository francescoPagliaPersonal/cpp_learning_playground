/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 12:55:41 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/26 13:15:36 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CURE_H
# define CURE_H

#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
	Cure(void);
	Cure(std::string const & type);
	Cure(const Cure& obj);
	Cure& operator=(const Cure& obj);
	~Cure(void);
	
	std::string const &	getType() const; //Returns the materia type
	virtual AMateria*	clone() const = 0;
	virtual void		use(ICharacter& target);

	protected:

	private:
	
};

#endif