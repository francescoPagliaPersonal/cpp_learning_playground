
#include "header.hpp"

std::vector<int> _jacobstahl;

void comparePairs(std::vector<node_s *> & arr, int level) 
{
	if (arr.size() < 2)
		return ;

	std::vector<node_s *>	winners;
	std::vector<node_s *>	sorted;
	node_s *				reminder = NULL;

	if (arr.size() % 2 != 0 )
		reminder = arr.back();
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
	std::cout << "\n\n[" << level << "]" 
			<< "\tarr.size: " << arr.size() 
			<< "\twin.size: " << winners.size() << std::endl;
	printchainR(winners, reminder);
	comparePairs(winners, ++level);
	
	
	std::vector<node_s *> looser;
	for (ptr_id id = 0; id < winners.size(); ++id){
		looser.push_back(winners[id]->childs.back());
		winners[id]->childs.pop_back();
	}
	
	if (reminder != NULL)
		looser.push_back(reminder);

	looser[0]->parent->prev = looser[0];
	looser[0]->next = winners[0];

	if (looser.size() < 2){
		winners.insert(winners.begin(), looser[0]);
		return ;
	}

	std::vector<int>jsSeq = getJacobSequence(looser.size());\
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