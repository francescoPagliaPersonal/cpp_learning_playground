/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 14:13:30 by fpaglia           #+#    #+#             */
/*   Updated: 2026/05/12 11:46:27 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_H
# define PMERGEME_H

# ifndef DEBUG
#  define DEBUG 0
# endif
# ifndef PRINT_ITEMS
#  define PRINT_ITEMS  5
# endif
#include <cstddef>
#include <deque>
#include <vector>
#include <string>
#include <iostream>

class PmergeMe 
{
	private:

	struct node_s {
		int			value;
		node_s		*parent;
		node_s		*prev;
		node_s		*next;
		std::vector<node_s *>	childs;

		node_s(void) ;
		node_s(int num);
	};


	
	public: 
	
	PmergeMe(void);
	PmergeMe(const PmergeMe & obj);
	~PmergeMe(void);
	PmergeMe& operator=(const PmergeMe & obj);
	
	void 	ingest(const char **arr);
	bool	mergeInsert(void);
	void	print(void);
	std::vector<int>	getSortedVector(void) const;
	std::deque<int>		getSortedDeque(void) const;
	
	

	private:
	
	std::vector<node_s>	_sourceItems;
	std::vector<int>	_vItems;
	std::deque<int>		_dItems;
	size_t				_vCounter;
	size_t				_dCounter;
	node_s *			_maxBound;
	std::string			_vTime;
	std::string			_dTime;

	
	static std::string				_getTimeDelta(struct timeval & begin);
	static std::vector<int>			_jacobstahlSeq(int size);
	int								_fordJohnsonBound(int n) const ;

	template<typename T > 
	static typename T::size_type	_findIndex(T const & arr, int value, size_t & counter);
	
	
	template<typename C, typename T >
	void			_value2pointers(C & db, T & ptrDb);

	template<typename T >
	node_s *		_executeSort(T & ptrDb, int level, size_t & counter, 
						T (*buildRange)(node_s * first, node_s * bound, typename T::size_type size));
	
	template<typename T >
	T 				_pairNodes(T const & arr, size_t & counter);

	template<typename T >
	node_s * 		_getInsertionNode(T const & numbers, int value, size_t & counter);

	static std::vector<node_s *>	_buildRangeVector(node_s * first, node_s * bound, std::vector<node_s *>::size_type size);
	static std::deque<node_s *>		_buildRangeDeque(node_s * first, node_s * bound, std::deque<node_s *>::size_type size);
	
	// from sorted list export arrays  -------------------->
	std::vector<int>				_list2vector(node_s *list);
	std::deque<int>					_list2deque(node_s *list);
	
	
	// print helpers -------------------->
	template<typename T>
	void	_printIterable(std::string title, T const & obj);
	
	void	_printNode_s(std::string title, std::vector<node_s> const & obj);
	void	_printNode_s(std::string title, std::vector<node_s> const & obj, int items);

	
	// debug printing -------------------->
	template<typename T>
	void	_printPairs(T container, node_s *reminder);
	
	template<typename T>
	void	_printLoosers(T container, node_s *reminder);
	
	template<typename T>
	void	_printContainerNode_s(std::string title, T container);

	template<typename T>
	void	_printContainerInt(std::string title, T container);
	
	template<typename T>
	void	_printContainerInt(std::string title, T container, typename T::size_type items);

	void	_printWinnerList(std::string title, node_s * winList);

	std::deque<node_s>	_vec2deq(std::vector<node_s> input);
	
};

template<typename C, typename T >
void PmergeMe::_value2pointers(C & db, T & ptrDb)
{
	typename C::size_type id;
	for (id = 0; id < db.size(); ++id)
		ptrDb.push_back(&db[id]);
}

template<typename T >
T PmergeMe::_pairNodes(T const & arr, size_t & counter)
{
	T	winners;
	typename T::size_type id;

	for (id = 0; id + 2 <= arr.size(); id += 2) {
		if (arr[id]->value > arr[id + 1]->value) {
			arr[id]->childs.push_back(arr[id + 1]);
			arr[id + 1]->parent = arr[id];
			winners.push_back(arr[id]);
		}
		else {
			arr[id + 1]->childs.push_back(arr[id]);
			arr[id]->parent = arr[id + 1];
			winners.push_back(arr[id + 1]);
		}
		counter++;
	}
	return winners;
}

template<typename T >
typename T::size_type PmergeMe::_findIndex(T const & arr, int value, size_t & counter) 
{
	typedef typename T::size_type T_id;
	
	T_id low = 0;
	T_id high = arr.size(); 
	T_id mid = -1;
	while (low < high) {
		mid = low + (high - low) / 2;
		counter++;
		if (arr[mid]->value < value) low = mid + 1;
		else high = mid;
	}
	return low;
}

template<typename T >
PmergeMe::node_s * PmergeMe::_getInsertionNode(T const & numbers, int value, size_t & counter)
{
	typename T::size_type	idx;
	
	idx = _findIndex(numbers, value, counter);
	if (idx >= numbers.size())
		return NULL;
	return numbers[idx];
}

template<typename T >
PmergeMe::node_s * 
PmergeMe::_executeSort(T & arr, int level, size_t & counter, 
						T (*buildRange)(node_s * first, node_s * bound, typename T::size_type size)) 
{
	if (arr.size() < 2) {
		if (DEBUG >= 1) {
			std::cout << "[" << level << "]";
			std::cout << "Max levels reached, starting insertion." << std::endl;
		}
		return arr[0];
	}

	T	winners;
	node_s *				reminder = NULL;

	if (arr.size() % 2 != 0 )
		reminder = arr.back();
	winners = _pairNodes(arr, counter);
	
	
	if (DEBUG >= 1) {
		std::cout << "\n\n[" << level << "]" 
				<< "\tarr.size: " << arr.size() 
				<< "\twin.size: " << winners.size() << std::endl;

		_printPairs(winners, reminder);
	}
	

	
	// START OF RECURSION HERE ----------------------->
	node_s * winList = _executeSort(winners, level + 1, counter, buildRange);
	if (_maxBound == NULL)
		_maxBound = winList;
	
	if (DEBUG >= 1) 
	{
		std::cout << "===================================================="<< std::endl;
		std::cout << "[" << level << "]";
		std::cout << "max_bound        : "<< _maxBound->value << std::endl;
		std::cout << "[" << level << "]";
		std::cout << "comparison count : " << counter << "\n"
				<< 	"----------------------------------------------------" << std::endl;
		std::cout << "[" << level << "]";
		_printWinnerList("incomin winners  : ", winList);
	}
	

	T looser;
	node_s * tmp = winList;
	// get the node_s child in the looser list
	
	
	while (tmp != NULL )
	{
		if (!tmp->childs.empty()) {
			looser.push_back(tmp->childs.back());
			tmp->childs.pop_back(); 
		}
		tmp = tmp->next;
	}
	
	// add the sparse looser if it was available
	if (reminder != NULL)
		looser.push_back(reminder);

	// insert the first looser in the winner list 
	looser[0]->parent->prev = looser[0];
	looser[0]->next = winList;
	looser[0]->parent = NULL;
	winList = looser[0];

	if (looser.size() <= 1) {
		if (DEBUG >= 1) 
		{
			std::cout << "[" << level << "]";
			_printWinnerList("current winners  : ", winList);
		}
		return winList;
	}

	std::vector<int> jsSeq = _jacobstahlSeq(looser.size());

	if (DEBUG >= 1) 
	{
		std::cout << "["<< level << "]";
		_printContainerNode_s("list of looser   : ",looser);

		std::cout << "[" << level << "]";
		_printContainerInt("jacobstahlSeq    : ", jsSeq);
		std::cout << "----------------------------------------------------" << std::endl;
	}

	// following the Jacobstahl sequence grow the list of winners

	for (size_t i = 1; i < looser.size(); ++i) 
	{
		T binSearchRange;
		node_s * currNode = looser[jsSeq[i]];
		node_s * rightBound = currNode->parent;
		if (DEBUG >= 1) 
			std::cout << "to insert: " << currNode->value << std::endl;
		if (rightBound != NULL) {
			binSearchRange = buildRange(winList, rightBound, looser.size() * 2);
			binSearchRange.pop_back();
		}
		else {
			if (DEBUG >= 1) 
				std::cout << "missing father starting from maxBound" << std::endl;
			rightBound = _maxBound;
			binSearchRange = buildRange(winList, rightBound, looser.size() * 2);
		}
		node_s * insertPoint = _getInsertionNode(binSearchRange, currNode->value, counter);
		
		if (DEBUG >= 1) 
			_printContainerNode_s("searchRange: ", binSearchRange);
		
		if (insertPoint == NULL && rightBound == _maxBound && currNode->parent == NULL) 
		{
			if (DEBUG >= 1) 
				std::cout << "No insertion point, generates new boundary : " << currNode->value << std::endl;
			currNode->prev = _maxBound;
			_maxBound->next = currNode;
			_maxBound = currNode;
		}
		else {
			if (insertPoint == NULL)
				insertPoint = rightBound;
			if (DEBUG >= 1) 
				std::cout << "insertion point: " << insertPoint->value << "\n" << std::endl;

			currNode->parent = NULL;
			currNode->next = insertPoint;
			if (insertPoint->prev != NULL) {
				currNode->prev = insertPoint->prev;
				insertPoint->prev->next = currNode;
				insertPoint->prev = currNode;
			}
			insertPoint->prev = currNode;
			if (insertPoint == winList)
			winList = currNode;

		}
	}
	
	if (DEBUG >= 1) 
	{
		std::cout << "[" << level << "]";
		_printWinnerList("current winners  : ", winList);
	}
	if (level == 0)
		_maxBound = NULL;
	return winList;
}


#include "PmergeMe.tpp" 

#endif
