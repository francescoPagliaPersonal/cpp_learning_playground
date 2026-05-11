/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.print.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 15:08:53 by fpaglia           #+#    #+#             */
/*   Updated: 2026/05/11 15:35:25 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	PmergeMe::_printNode_s(std::string title, std::vector<node_s> const & obj)
{
	std::cout << "\nPRINTING "<< title << ": "<< std::endl;
	std::vector<node_s>::const_iterator it = obj.begin();
	std::vector<node_s>::const_iterator ite = obj.end();
	if (it == ite)
		return;
	--ite;
	while (it != ite )
	{
		std::cout << it->value << ", ";
		++it;
	}
	std::cout << it->value << "." << std::endl;
}


void PmergeMe::_printWinnerList(std::string title, node_s * winList)
{
	if (winList == NULL)
		return;
	
	std::cout << title ;
	
	node_s * tmp = winList;
	while (tmp != NULL) {
		std::cout << tmp->value << " ";
		tmp = tmp->next;
	}
	std::cout << std::endl;
}