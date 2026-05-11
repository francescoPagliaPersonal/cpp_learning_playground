/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.mergeInsert.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 13:56:57 by fpaglia           #+#    #+#             */
/*   Updated: 2026/05/11 15:40:06 by fpaglia          ###   ########.fr       */
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

	std::deque<node_s>		democopy = _vec2deq(_sourceItems);
	
	std::cout << "/////////////////////////////////////////////////" << "\n"
			<< "sorting with vector:" << std::endl;
	_value2pointers(_sourceItems, vWinner);
	vList = _executeSort(vWinner, 0, _vCounter, _buildRangeVector);
	_vItems = _list2vector(vList);

	
	std::cout << "sorting completed.\n" 
			<< "/////////////////////////////////////////////////" << "\n"
			<< "sorting with deque:" << std::endl;
	
	_value2pointers(democopy, dWinner);
	dList = _executeSort(dWinner, 0, _dCounter, _buildRangeDeque);
	_dItems = _list2deque(dList);
	
	return true;
}
