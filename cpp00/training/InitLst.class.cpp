/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InitLst.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 11:43:45 by fpaglia           #+#    #+#             */
/*   Updated: 2026/01/28 12:31:21 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "InitLst.class.hpp"

InitLst::InitLst(int num, char word, float dotnum) : i1(num), c1(word), f1(dotnum) {

	std::cout << "InitLst " << this->c1 << " created." << std::endl;
	return ;
}

InitLst::~InitLst(void) {

	std::cout << "InitLst destroyed" << std::endl;
	return ;
}

/* The function is marked constant to refer to the fact that the inputs bought via 
 * 'this->' must not be modified within this function.
 */
void	InitLst::report(void) const {

	std::cout << "Public parameters:"
			<<   "\n 1: " << this->i1
			<<	 "\n 2: " << this->c1
			<<   "\n 3: " << this->f1
			<< std::endl;
	return ;
}

