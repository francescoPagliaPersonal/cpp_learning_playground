/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 22:49:30 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/06 22:49:32 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack(); 
		club.setType("some other type of club"); 
		bob.attack();
	}
	{ 
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim"); 
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack(); 
	}
	{
		Weapon *club = new Weapon("dark sword");
		HumanB mark("mark");
		mark.attack();
		mark.setWeapon(*club);
		mark.attack();
		club->setType("tiny knife");
		mark.attack();
		delete club;
	}
	return 0;
}