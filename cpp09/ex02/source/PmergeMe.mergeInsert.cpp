/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.mergeInsert.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 13:56:57 by fpaglia           #+#    #+#             */
/*   Updated: 2026/05/11 10:46:53 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <deque>
#include <vector>

bool PmergeMe::mergeInsert(void) {
	std::vector<node_s *>	vWinner;
	std::deque<node_s *>	dWinner;
	
	node_s*					vList;
	node_s*					dList;
	
	std::cout << "/////////////////////////////////////////////////" << "\n"
			<< "sorting with vector:" << std::endl;
	value2pointers(_sourceItems, vWinner);
	vList = executeSort(vWinner, 0, _vCounter, buildRangeVector);
	_vItems = list2vector(vList);

	std::cout << "sorting completed.\n" 
			<< "/////////////////////////////////////////////////" << "\n"
			<< "sorting with deque:" << std::endl;
	std::vector<node_s>		democopy(_sourceItems);
	value2pointers(democopy, dWinner);
	dList = executeSort(dWinner, 0, _dCounter, buildRangeDeque);
	_dItems = list2deque(dList);
	
	return true;
}
