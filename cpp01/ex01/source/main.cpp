/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 14:45:57 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/06 14:45:58 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie *zombies;
	Zombie father("Father");
	int		count = 50;
	
	zombies = father.zombieHorde(count, "Child");
	for (int i = 0; i < count; ++i)
		zombies[i].announce();
	delete [] zombies;
	return (0);
}
