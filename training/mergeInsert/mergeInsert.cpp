
#include "header.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>

int __counter = 0;
node_s * maxBound = NULL;

std::vector<node_s *> pairNodes(std::vector<node_s *> & arr)
{
	std::vector<node_s *>	winners;

	for (ptr_id id = 0; id + 2 <= arr.size(); id += 2) {
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
		__counter++;
	}
	return winners;
}

std::vector<node_s *> buildRange(node_s * last) 
{	
	std::vector<node_s *> arr;
	
	arr.push_back(last);
	
	node_s * tmp = last->prev;
	
	while (tmp != NULL)
	{
		arr.insert(arr.begin(), tmp);
		tmp = tmp->prev;
	}
	return arr;
}

node_s * getInsertionNode(std::vector<node_s *> & numbers, int value)
{
	ptr_id	idx;
	idx = findIndex(numbers, value);
	if (idx >= numbers.size())
		return NULL;
	return numbers[idx];
}

node_s * comparePairs(std::vector<node_s *> & arr, int level) 
{
	if (arr.size() < 2) {
		maxBound = arr[0];
		return arr[0];
	}

	std::vector<node_s *>	winners;
	node_s *				reminder = NULL;

	if (arr.size() % 2 != 0 )
		reminder = arr.back();
	winners = pairNodes(arr);
	if (DEBUG >= 1) {
		std::cout << "\n\n[" << level << "]" 
				<< "\tarr.size: " << arr.size() 
				<< "\twin.size: " << winners.size() << std::endl;

		printchainR(winners, reminder);
	}

	
	// START OF RECURSION HERE ----------------------->
	node_s * winList = comparePairs(winners, level + 1);
	
	std::cout << "===================================================="<< std::endl;
	std::cout << "[" << level << "]";
	std::cout << "comparison count :" << __counter << std::endl;
	std::cout << "[" << level << "]";
	printWinnerList("incomin winners:", winList);

	std::vector<node_s *> looser;
	node_s * tmp = winList;
	// get the node_s child in the looser list
	// int i = 0;
	std::cout << "[" << level << "]";
	std::cout << "capture looser: ";
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
		// i++;
	}
	std::cout << std::endl;
	// add the sparse looser if it was available
	if (reminder != NULL)
		looser.push_back(reminder);

	// insert the first looser in the winner list 
	// looser[0]->parent->prev = looser[0];
	winList->prev = looser[0];
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
	printVectorNode_s("list of looser: ",looser);
	std::vector<int> jsSeq = jacobstahlSeq(looser.size());
	std::cout << "[" << level << "]";
	printVectorInt("jacobstahlSeq:  ", jsSeq);
	std::cout << "maxbound: " << maxBound->value << "\n"<< std::endl;

	// following the Jacobstahl sequence grow the list of winners

	for (size_t i = 1; i < looser.size(); ++i) 
	{
		std::vector<node_s *> binSearchRange;
		node_s * currNode = looser[jsSeq[i]];
		// std::cout << "currNode:" << currNode->value << " father: " << currNode->parent <<std::endl;
		node_s * rightBound = currNode->parent;
		if (rightBound != NULL)
			binSearchRange = buildRange(rightBound);
		else {
			std::cout << "missing father starting from maxBound" << std::endl;
			binSearchRange = buildRange(maxBound);
		}
		binSearchRange.pop_back();
		node_s * insertPoint = getInsertionNode(binSearchRange, currNode->value);
		std::cout << "to insert: " << currNode->value << std::endl;
		printVectorNode_s("searchRange: ", binSearchRange);
		if (insertPoint == NULL)
			insertPoint = maxBound;
		std::cout << "insertion point: " << insertPoint->value << std::endl;
			// throw std::invalid_argument("Pointer must not have been null!!!");
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

	if (DEBUG >= 1) 
	{
		std::cout << "[" << level << "]";
		printWinnerList("current winners:", winList);
	}
	return winList;
}


int main(void) 
{
	std::vector<node_s>		numbers;
	// int unordered[] = {5,2,14,19,20,17,4,12,15,7, 13,16,1,8,6,21,3,10,9,18,11};
	// int unordered[] = {21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	int unordered[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21};

	// populateJacobNumber(sizeof(unordered)/ sizeof(unordered[0]));
	std::vector<int>	jsNum = jacobstahlSeq(16);

	std::cout << "jacobStahl number: ";
	for (size_t i = 0; i < jsNum.size(); ++i)
		std::cout << jsNum[i] << " ";
	std::cout << std::endl;

	for (size_t i = 0; i < sizeof(unordered)/ sizeof(unordered[0]); ++i)
	{
		node_s	tmp(unordered[i]);
		numbers.push_back(tmp);
	}
	// printchain(numbers);
	std::vector<node_s *>	winners;
	for (vec_id id = 0; id < numbers.size(); ++id)
		winners.push_back(&numbers[id]);
	// printchainR(winners, NULL);
	node_s * winList = comparePairs(winners, 1);

	printVectorNode_s("\nORIGINAL LIST: \n", numbers);
	printWinnerList("\nFINAL LIST: \n", winList);
	std::cout << "\n\nmax expected count: " << fordJohnsonBound(21) << std::endl;
	std::cout << "comparison: " << __counter << std::endl;

}