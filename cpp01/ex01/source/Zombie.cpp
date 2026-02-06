/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 14:45:52 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/06 14:45:53 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void) : name("") {}

Zombie::Zombie(std::string name) : name(name)
{
	std::cout << this->name << ": joined the party" << std::endl;
}

Zombie::~Zombie(void) 
{
	std::cout << this->name << ": is gone..." << std::endl;
}

void	Zombie::announce(void) const
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->name = name;
}

