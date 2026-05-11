/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 14:13:30 by fpaglia           #+#    #+#             */
/*   Updated: 2026/05/11 15:16:23 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_H
# define PMERGEME_H

# ifndef DEBUG
#  define DEBUG 0
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
	

	// typedef std::vector<node_s *>::size_type	ptrV_id;
	// typedef std::deque<node_s *>::size_type		ptrD_id;

	
	public: 
	
	PmergeMe(void);
	PmergeMe(const PmergeMe & obj);
	~PmergeMe(void);
	PmergeMe& operator=(const PmergeMe & obj);
	
	void 	ingest(const char **arr);
	bool	mergeInsert(void);
	int		mergeSort(std::vector<int> & db);
	int		mergeSort(std::deque<int> & db);
	void	print(void);
	
	

	private:
	
	std::vector<node_s>	_sourceItems;
	std::vector<int>	_vItems;
	std::deque<int>		_dItems;
	size_t				_vCounter;
	size_t				_dCounter;
	node_s *			_maxBound;

	
	static	std::vector<int>		jacobstahlSeq(int size);
	int								fordJohnsonBound(int n) const ;

	template<typename T > 
	static typename T::size_type	findIndex(T const & arr, int value, size_t & counter);
	
	
	template<typename C, typename T >
	void			value2pointers(C & db, T & ptrDb);

	template<typename T >
	node_s *		executeSort(T & ptrDb, int level, size_t & counter, T (*buildRange)(node_s * bound));
	
	template<typename T >
	T 				pairNodes(T const & arr, size_t & counter);

	template<typename T >
	node_s * 		getInsertionNode(T const & numbers, int value, size_t & counter);

	static std::vector<node_s *>	buildRangeVector(node_s * last) ;
	static std::deque<node_s *>		buildRangeDeque(node_s * last) ;
	
	
	std::vector<int>				list2vector(node_s *list);
	std::deque<int>					list2deque(node_s *list);
	
	
	template<typename T>
	void	_printIterable(std::string title, T const & obj);
	
	void	_printNode_s(std::string title, std::vector<node_s> const & obj);

	
	// debug printing -------------------->
	template<typename T>
	void printLoosers(T container, node_s *reminder);
	
	template<typename T>
	void printVectorNode_s(std::string title, T container);

	void printWinnerList(std::string title, node_s * winList);

	std::deque<node_s>	vec2deq(std::vector<node_s> input);
	
};

template<typename C, typename T >
void PmergeMe::value2pointers(C & db, T & ptrDb)
{
	typename C::size_type id;
	for (id = 0; id < db.size(); ++id)
		ptrDb.push_back(&db[id]);
}

template<typename T >
T PmergeMe::pairNodes(T const & arr, size_t & counter)
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
typename T::size_type PmergeMe::findIndex(T const & arr, int value, size_t & counter) 
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
PmergeMe::node_s * PmergeMe::getInsertionNode(T const & numbers, int value, size_t & counter)
{
	typename T::size_type	idx;
	
	idx = findIndex(numbers, value, counter);
	if (idx >= numbers.size())
		return NULL;
	return numbers[idx];
}

template<typename T >
PmergeMe::node_s * PmergeMe::executeSort(T & arr, int level, size_t & counter, T (*buildRange)(node_s * bound)) 
{
	if (arr.size() < 2) {
		std::cout << "[" << level << "]";
		std::cout << "Levels       : "<< level 
					<< " reached Top!" << std::endl;
		return arr[0];
	}

	T	winners;
	node_s *				reminder = NULL;

	if (arr.size() % 2 != 0 )
		reminder = arr.back();
	winners = pairNodes(arr, counter);
	
	
	if (DEBUG >= 1) {
		std::cout << "\n\n[" << level << "]" 
				<< "\tarr.size: " << arr.size() 
				<< "\twin.size: " << winners.size() << std::endl;

		printLoosers(winners, reminder);
	}
	

	
	// START OF RECURSION HERE ----------------------->
	node_s * winList = executeSort(winners, level + 1, counter, buildRange);
	if (_maxBound == NULL)
		_maxBound = winList;
	
	std::cout << "===================================================="<< std::endl;
	std::cout << "[" << level << "]";
	std::cout << "max_bound        : "<< _maxBound->value << std::endl;
	std::cout << "[" << level << "]";
	std::cout << "comparison count : " << counter << std::endl;
	std::cout << "[" << level << "]";
	printWinnerList("incomin winners  : ", winList);
	

	T looser;
	node_s * tmp = winList;
	// get the node_s child in the looser list
	

	
	std::cout << "[" << level << "]";
	std::cout << "capture looser   : ";
	
	while (tmp != NULL )
	{
		if (!tmp->childs.empty()) {
			looser.push_back(tmp->childs.back());
			tmp->childs.pop_back(); 
			std::cout << looser.back()->value << " ";
		}
		else {
			std::cout << "   ";
		}
		tmp = tmp->next;
	}
	std::cout << std::endl;
	
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
			printWinnerList("current winners:", winList);
		}
		return winList;
	}

	
	std::cout << "["<< level << "]";
	printVectorNode_s("list of looser   : ",looser);
	
	
	std::vector<int> jsSeq = jacobstahlSeq(looser.size());
	
	std::cout << "[" << level << "]";
	_printIterable("jacobstahlSeq:  ", jsSeq);
	std::cout << "maxbound: " << _maxBound->value << "\n"<< std::endl;

	// following the Jacobstahl sequence grow the list of winners

	for (size_t i = 1; i < looser.size(); ++i) 
	{
		T binSearchRange;
		node_s * currNode = looser[jsSeq[i]];
		// std::cout << "currNode:" << currNode->value << " father: " << currNode->parent <<std::endl;
		node_s * rightBound = currNode->parent;
		if (rightBound != NULL)
			binSearchRange = buildRange(rightBound);
		else {
			std::cout << "missing father starting from maxBound" << std::endl;
			rightBound = _maxBound;
			binSearchRange = buildRange(rightBound);
		}
		binSearchRange.pop_back();
		node_s * insertPoint = getInsertionNode(binSearchRange, currNode->value, counter);
		
		std::cout << "to insert: " << currNode->value << std::endl;
		printVectorNode_s("searchRange: ", binSearchRange);
		if (insertPoint == NULL && rightBound == _maxBound ) 
		{
			std::cout << "No insertion point, generates new boundary : " << currNode->value << std::endl;
			currNode->prev = _maxBound;
			_maxBound->next = currNode;
			_maxBound = currNode;
		}
		else {
			if (insertPoint == NULL)
			insertPoint = rightBound;
			std::cout << "insertion point: " << insertPoint->value << std::endl;

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
		printWinnerList("current winners  : ", winList);
	}
	
	return winList;
}


#include "PmergeMe.tpp" 

#endif
