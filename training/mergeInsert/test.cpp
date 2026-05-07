#include "header.hpp"
#include <vector>

int __counter = 0;

void insertValue(std::vector<int> & numbers, int value)
{
	idx_id	idx;
	idx = findIndex(numbers, value);
	numbers.insert(numbers.begin() + idx, value);
}

int main(void) 
{
	int arr[] = {2, 5, 7, 13, 25};
	
	std::vector<int>	numbers;
	for (size_t i = 0; i < 5; ++i)
		numbers.push_back(arr[i]);	
	
	std::vector<int>	incrNumbers;
	for (size_t i = 0; i < 46; ++i)
		incrNumbers.push_back(i);	
	
	{
		std::cout << "\n======== Test findIndex ========"  << std::endl;
		printVectorInt("Before insertion: ", numbers);
		insertValue(numbers, 24);
		insertValue(numbers, 0);
		insertValue(numbers, 26);	
		printVectorInt("After insertion : ", numbers);
	}
	{
		std::cout << "\n\n======== Test jacobNumebers ========"  << std::endl;
		printVectorInt("Numbered   list: \n", incrNumbers);
		std::cout << "list size: " << incrNumbers.size() << std::endl;
		std::vector<int>	jsSeries = getJacobSequence(incrNumbers.size() - 1);
		printVectorInt("Jacobstahl list: \n", jsSeries);
		std::cout << "list size: " << jsSeries.size() << std::endl;
		std::cout << "Numbered list ordered following the index of JacobStahl list: " << std::endl;
		for (size_t i = 0; i < jsSeries.size(); ++i)
		{
			std::cout << incrNumbers[jsSeries[i]] << " ";
		}
		std::cout << std::endl;
	}

}