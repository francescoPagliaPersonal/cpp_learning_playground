/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 14:44:58 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/26 16:31:17 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure(void) : AMateria("cure") {}
Cure::Cure(const Cure& obj) : AMateria(obj._type) {}
Cure::~Cure(void) {}

Cure& Cure::operator=(const Cure& obj)
{
	if (this != &obj)
		_type = obj._type;
	return (*this);
}

AMateria* Cure::clone() const
{
	return (new Cure(*this));
}

void	Cure::use(ICharacter& target) const
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}