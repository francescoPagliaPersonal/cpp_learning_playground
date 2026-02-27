/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fire.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 14:44:58 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/27 18:06:36 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fire.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

Fire::Fire(void) : AMateria("fire") {}
Fire::Fire(const Fire& obj) : AMateria(obj._type) {}
Fire::~Fire(void) {}

Fire& Fire::operator=(const Fire& obj)
{
	if (this != &obj)
		_type = obj._type;
	return (*this);
}

AMateria* Fire::clone() const
{
	return (new Fire(*this));
}

void	Fire::use(ICharacter& target) const
{
	std::cout << "* warms up " << target.getName() << "with a magnificent fire *"
			<< std::endl;
}