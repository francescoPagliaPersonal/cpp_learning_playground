#include "header.hpp"
#include <vector>

int __counter = 0;

node_s * insertValue(std::vector<node_s *> & numbers, int value)
{
	ptr_id	idx;
	idx = findIndex(numbers, value);
	if (idx >= numbers.size())
		return NULL;
	return numbers[idx];
}

int main(void) 
{
	int arr[] = {2, 5, 7, 13, 25};
	
	std::vector<node_s>	numbers;
	for (size_t i = 0; i < 5; ++i){
		node_s tmp(arr[i]);
		numbers.push_back(tmp);	
	}
	
	std::vector<node_s *> ptrArr;
	for (size_t i = 0; i < numbers.size(); ++i)
		ptrArr.push_back(&numbers[i]);

	std::vector<int>	incrNumbers;
	for (size_t i = 0; i < 46; ++i)
		incrNumbers.push_back(i);
	
	{
		std::vector<node_s> tmp;
		tmp.push_back(node_s(24));
		tmp.push_back(node_s(0));
		tmp.push_back(node_s(26));
		std::cout << "\n======== Test findIndex ========"  << std::endl;
		printVectorNode_s("Before insertion: ", numbers);
		// ptr_id idx = findIndex(ptrArr, 24);
		std::cout << "inserting 24 before: " << insertValue(ptrArr, 24)->value << std::endl;
		std::cout << "inserting 0  before: " << insertValue(ptrArr, 0)->value << std::endl;
		std::cout << "inserting 26 before: " << (insertValue(ptrArr, 26) == NULL ? "NULL": "ERROR") << std::endl;
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
		
		for (size_t i = 0; i < ptrArr.size() - 1; ++i) {
			ptrArr[i]->next =  ptrArr[i + 1];
		}
		printVectorNode_s("array printed in vect form : ", ptrArr);
		printWinnerList("array printed in list form : ", ptrArr[0]);
	}

}

