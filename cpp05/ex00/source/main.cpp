/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 15:06:38 by fpaglia           #+#    #+#             */
/*   Updated: 2026/03/31 13:36:49 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <ostream>

int main()
{
	Bureaucrat sad;
	Bureaucrat sad01("Martin");
	Bureaucrat sad02("Rob", 35);
	Bureaucrat sad03("Bob", -1);
	Bureaucrat sad04("Sob", 200);
		
	std::cout << sad << "\n"
			<< sad01 << "\n"
			<< sad02 << "\n"
			<< sad03 << "\n"
			<< sad04 << "\n"
			<< std::endl;
	sad02.increment(100);
	std::cout << "after increment " <<  sad02 << std::endl;
	sad02.decrement(100);
	std::cout <<  "after 1st decrement " << sad02 << std::endl;
	sad02.decrement(100);
	std::cout <<  "after 2nd decrement " << sad02 << std::endl;


}
