/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 14:13:44 by fpaglia           #+#    #+#             */
/*   Updated: 2026/05/12 11:07:45 by fpaglia          ###   ########.fr       */
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
	if (DEBUG == 0)
		_printNode_s("Before: ", _sourceItems, PRINT_ITEMS);
	
	if (DEBUG >= 1) {
		std::cout << "\n\n====================================================\n\n"<< std::endl;
		_printNode_s("Unsorted input : \n", _sourceItems);
		std::cout << "Max comparisons : " 
				<< _fordJohnsonBound(_sourceItems.size()) << "\n" << std::endl;
	}
	if (DEBUG == 0)
		_printContainerInt("After: ", _vItems, PRINT_ITEMS);
	
	if (DEBUG >= 1) {
		_printContainerInt("Sorted vector   : \n", _vItems);
		std::cout << "Comparisons     : " << _vCounter << "\n" << std::endl;
		_printContainerInt("Sorted deque    : \n", _dItems);
		std::cout << "Comparisons     : " << _dCounter << "\n" << std::endl;
	}
	
	std::cout	<< "Time to process a range of "	<< _vItems.size() 
				<< " elements with std::vector : "	<< _vTime
				<< " us" << std::endl;
	std::cout	<< "Time to process a range of "	<< _dItems.size() 
				<< " elements with std::deque  : "	<< _dTime
				<< " us" << std::endl;
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