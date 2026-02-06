/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 17:08:42 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/06 17:08:44 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *Zombie::zombieHorde(int N, std::string name)
{
	Zombie *tmp = new Zombie[N];

	for (int i = 0; i < N; ++i)
	{
		std::ostringstream tostr;
		tostr << name << "_" << i + 1;
		tmp[i].setName(tostr.str());
	}
	return (tmp);
}