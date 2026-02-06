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
	Zombie stefan("Stefan");
	stefan.randomChump("Qui");
	stefan.randomChump("Quo");
	stefan.randomChump("Qua");
	Zombie *sergio = stefan.newZombie("sergio");
	sergio->announce();
	delete sergio;
	return (0);
}
