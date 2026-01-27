/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Trial.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 09:52:04 by fpaglia           #+#    #+#             */
/*   Updated: 2026/01/27 10:42:07 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Trial.class.hpp"

Trial::Trial(void) {

	std::cout << "Constructor called" << std::endl;
	return ;
}

Trial::~Trial(void) {

	std::cout << "Destructor called" << std::endl;
	return ;
}

void	Trial::foofunct(void) {

	std::cout << "writing from a member function" << std::endl;
	return ;
}
