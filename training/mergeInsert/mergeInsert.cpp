
#include "header.hpp"
#include <vector>

std::vector<node_s *> pairNodes(std::vector<node_s *> & arr)
{
	std::vector<node_s *>	winners;

	for (ptr_id id = 0; id + 2 <= arr.size(); id += 2) {
		if (arr[id]->value > arr[id + 1]->value) {
			arr[id]->childs.push_back(arr[id + 1]);
			arr[id]->wins += 1;
			arr[id + 1]->parent = arr[id];
			winners.push_back(arr[id]);
		}
		else {
			arr[id + 1]->childs.push_back(arr[id]);
			arr[id + 1]->wins += 1;
			arr[id]->parent = arr[id + 1];
			winners.push_back(arr[id + 1]);
		}
		__counter++;
	}
	return winners;
}

std::vector<node_s> buildRange(node_s * last) 
{	
	std::vector<node_s> arr;
	arr.push_back(*last);

	node_s * tmp = last->prev;

	while (last != NULL)
	{
		arr.insert(arr.begin(), *tmp);
		tmp = tmp->prev;
	}
	return arr;
}

node_s * comparePairs(std::vector<node_s *> & arr, int level) 
{
	if (arr.size() < 2)
		return arr[0];

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
	node_s * winList = comparePairs(winners, ++level);
	
	
	std::vector<node_s *> looser;
	node_s * tmp = winList;
	
	// get the node_s child in the looser list
	if (tmp->next == NULL){
		looser.push_back(tmp->childs.back());
		tmp->childs.pop_back();
	}
	while (tmp->next != NULL) {
		looser.push_back(tmp->childs.back());
		tmp->childs.pop_back();
		tmp = tmp->next;
	}
	// add the sparse looser if it was available
	if (reminder != NULL)
		looser.push_back(reminder);

	// insert the first looser in the winner list 
	looser[0]->parent->prev = looser[0];
	looser[0]->next = winList;
	winList = looser[0];

	if (looser.size() <= 1) 
		return winList;

	// following the Jacobstahl sequence grow the list of winners
	std::vector<int> jsSeq = getJacobSequence(looser.size());
	for (size_t i = 1; i < looser.size(); ++i) 
	{
		std::vector<node_s> binSearchRange;
		node_s * rightBound = looser[i]->parent;
		binSearchRange = buildRange(rightBound->prev);

	}

	if (DEBUG >= 1) 
	{
		std::cout << "[" << level << "]";
		printWinnerList("current winners:", winList);
	}
	return winList;
	/*
	
	node_s	*start = looser[0];

	for (size_t i = 0; i < jsSeq.size(); ++i)
	{
		node_s 	*win = looser[jsSeq[i]]->parent;
		node_s	*los = looser[jsSeq[i]];
		
		std::vector<int>	binarr;
		binarr.push_back(win->value);
		win = win->prev;
		while (win->prev != NULL)
			binarr.insert(binarr.begin(), win->value);

		idx_id index = findIndex(binarr, los->value);  // TODO create the binary search method do find the index
		for (int i = 0; i < index; ++i)
			start = start->next;
		insertNode(start, los); // TODO add a method  to insert the value
	}
	winners = rebuidWinnerArray(start);  // decide what to pass back... probably is just enough to pass the beginning of the winner list!!
	// up to here I created a chain of relationship so each child knows it's parent and 
	// each parent know the order of it's child with a vector.
	// now how can I reinsert the loosers  taking advantage of the connection I created avoiding any unnecessary comparison?
	*/
}


int main(void) 
{
	std::vector<node_s>		numbers;
	int unordered[] = {5,2,14,19,20,17,4,12,15,7,13,16,1,8,6,21,3,10,9,18,11};

	// populateJacobNumber(sizeof(unordered)/ sizeof(unordered[0]));
	std::vector<int>	jsNum = getJacobSequence(16);

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
	comparePairs(winners, 1);
	// printChildPar(numbers);

	std::cout << "\n\ncomparison: " << __counter << std::endl;

}