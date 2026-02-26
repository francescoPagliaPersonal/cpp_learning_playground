/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 13:18:10 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/26 13:33:26 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(void) : _type("") {}
AMateria::AMateria(std::string const & type) : _type(type) {};
AMateria::AMateria(const AMateria& obj) : _type(obj._type) {};
AMateria::~AMateria(void) {}

AMateria& AMateria::operator=(const AMateria& obj)
{
	if (this != &obj)
		this->_type = obj._type;
	return (*this);
}

std::string const &	AMateria::getType() const
{
	return (_type);
}
