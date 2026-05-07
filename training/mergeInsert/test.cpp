#include "header.hpp"
#include <vector>

int __counter = 0;

void insertValue(std::vector<node_s> & numbers, int value)
{
	idx_id	idx;
	idx = findIndex(numbers, value);
	numbers.insert(numbers.begin() + idx, value);
}

int main(void) 
{
	int arr[] = {2, 5, 7, 13, 25};
	
	std::vector<node_s>	numbers;
	for (size_t i = 0; i < 5; ++i){
		node_s tmp(arr[i]);
		numbers.push_back(tmp);	
	}
	std::vector<int>	incrNumbers;
	for (size_t i = 0; i < 46; ++i)
		incrNumbers.push_back(i);	
	
	{
		std::cout << "\n======== Test findIndex ========"  << std::endl;
		printVectorNode_s("Before insertion: ", numbers);
		insertValue(numbers, 24);
		insertValue(numbers, 0);
		insertValue(numbers, 26);	
		printVectorNode_s("After insertion : ", numbers);
	}
	{
		std::cout << "\n\n======== Test jacobNumebers ========"  << std::endl;
		printVectorInt("Numbered   list: \n", incrNumbers);
		std::cout << "list size: " << incrNumbers.size() << std::endl;
		std::vector<int>	jsSeries = getJacobSequence(incrNumbers.size());
		printVectorInt("Jacobstahl list: \n", jsSeries);
		std::cout << "list size: " << jsSeries.size() << std::endl;
		std::cout << "Numbered list ordered following the index of JacobStahl list: " << std::endl;
		for (size_t i = 0; i < jsSeries.size(); ++i)
		{
			std::cout << incrNumbers[jsSeries[i]] << " ";
		}
		std::cout << std::endl;
	}
	{
		std::cout << "\n\n======== Test printList ========"  << std::endl;
		for (size_t i = 0; i < numbers.size() - 1; ++i) {
			numbers[i].next =  &numbers[i + 1];
		}
		printVectorNode_s("array printed in vect form : ", numbers);
		printWinnerList("array printed in list form : ", &numbers[0]);
	}

}

