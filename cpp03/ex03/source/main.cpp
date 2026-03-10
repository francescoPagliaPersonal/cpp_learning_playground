/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 16:22:17 by fpaglia           #+#    #+#             */
/*   Updated: 2026/03/10 18:25:19 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"
#include <iostream>

int main(void)
{
	std::cout << "---------- CLAP ------------\n" << std::endl;
	ClapTrap cl01("clap_obj");
	
	std::cout << "\n---------- SCAV ------------\n" << std::endl;
	ScavTrap sc01("scav_obj");
	
	std::cout << "\n---------- FRAG ------------\n" << std::endl;
	FragTrap fr01("frag_obj");

	std::cout << "\n---------- DIAMOND ------------\n" << std::endl;
	DiamondTrap di01("diamond_obj");

	
	std::cout << "\n---------- REPORTS ------------\n" << std::endl;
	cl01.report();
	fr01.report();
	sc01.report();
	di01.report();
	
	std::cout << "\n---------- ATTACK VALUES ------------\n" << std::endl;
	cl01.attack("a scav");
	fr01.attack("a scav");
	sc01.attack("a frag");
	di01.attack("all the others");

	
	std::cout << "\n---------- SPECIALIZED ACTIONS ------------\n" << std::endl;
	di01.highFivesGuys();
	di01.guardGate();
	di01.whoAmI();
	
	std::cout << "\n---------- CONSTRUCTOR TESTS ------------\n" << std::endl;
	DiamondTrap di03(di01);
	DiamondTrap di02;

	di02 = di03;
	di02.whoAmI();
	di03.whoAmI();
	di02.report();
	di03.report();
	
	std::cout << "\n---------- DESTRUCTORS ------------\n" << std::endl;
	
	
	return (0);
}
