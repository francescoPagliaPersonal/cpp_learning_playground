/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 14:44:58 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/26 16:30:59 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

Ice::Ice(void) : AMateria("ice") {}
Ice::Ice(const Ice& obj) : AMateria(obj._type) {}
Ice::~Ice(void) {}

Ice& Ice::operator=(const Ice& obj)
{
	if (this != &obj)
		_type = obj._type;
	return (*this);
}

AMateria* Ice::clone() const
{
	return (new Ice(*this));
}

void	Ice::use(ICharacter& target) const
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}