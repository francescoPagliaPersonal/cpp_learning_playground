/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 16:22:17 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/19 16:22:19 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScavTrap.hpp"
#include <sstream>

int main(void)
{

	ScavTrap test;
	test.getName();
	test.setName("Pupillo");
	test.report();
	test.guardGate();
	ScavTrap test01("Giorgio");
	test01.report();
	test01.attack("Pupillo");
	ScavTrap test02(test01);
	test02.setName(test02.getName() + "_copy");
	test02.attack("Pupil");
	test02.report();
	ScavTrap test03;
	test03 = test02;
	test03.setName(test02.getName() + "_copy");
	for (int i = 0; i < 52; ++i)
	{
		std::ostringstream tostr;
		tostr << "ennemy_" << i ;
		test02.attack(tostr.str());
	}
	return (0);
}
