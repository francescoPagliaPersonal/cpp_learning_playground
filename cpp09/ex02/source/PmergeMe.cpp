/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 14:13:44 by fpaglia           #+#    #+#             */
/*   Updated: 2026/05/08 15:11:04 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"



PmergeMe::~PmergeMe(void) {};

PmergeMe::PmergeMe(void) : 
	_vCounter(0),
	_dCounter(0),
	_maxBound(NULL) {};

PmergeMe::PmergeMe(const PmergeMe & obj) : 
	_sourceItems(obj._sourceItems), 
	_vItems(obj._vItems), 
	_dItems(obj._dItems),  
	_vCounter(obj._vCounter),
	_dCounter(obj._dCounter),
	_maxBound(obj._maxBound) {} ;

PmergeMe& PmergeMe::operator=(const PmergeMe & obj) 
{
	if (this == &obj)
		return *this;
	
	_sourceItems = obj._sourceItems;
	_vItems = obj._vItems;
	_dItems = obj._dItems;
	_vCounter = obj._vCounter;
	_dCounter = obj._dCounter;
	_maxBound = obj._maxBound;
	return *this;
};

void PmergeMe::print(void)  {
	_printNode_s("Input", _sourceItems);
	_printIterable("Sorted vector", _vItems);
	std::cout << "Comparisons : " << _vCounter << std::endl;
	_printIterable("Sorted deque", _vItems);
	std::cout << "Comparisons : " << _dCounter << std::endl;
}

PmergeMe::node_s::node_s(void) : 
	value(-1), 
	parent(NULL),
	prev(NULL),
	next(NULL) {};

PmergeMe::node_s::node_s(int num) : 
	value(num), 
	parent(NULL),
	prev(NULL),
	next(NULL) {};