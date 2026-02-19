/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 11:13:22 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/19 12:47:42 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"


int main(void)
{
	ClapTrap soldier("Konan");
	ClapTrap opponent;
	ClapTrap reference;
	reference = soldier;
	
	opponent.setName("Shiroyama");
	soldier.setName("Little bird");

	soldier.attack(opponent.getName());
	opponent.takeDamage(soldier.getAttackDamage());
	soldier.setattackDamage(4);
	soldier.attack(opponent.getName());
	opponent.takeDamage(soldier.getAttackDamage());
	soldier.setattackDamage(6);
	soldier.attack(opponent.getName());
	opponent.takeDamage(soldier.getAttackDamage());

	reference.attack("A new soldier");
	reference.beRepaired(50);
	return (0);
}
