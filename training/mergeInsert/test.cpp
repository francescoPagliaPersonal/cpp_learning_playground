#include "header.hpp"
#include <vector>

int __counter = 0;

void insertValue(std::vector<int> & numbers, int value)
{
	idx_id	idx;
	idx = findIndex(numbers, value);
	std::cout  << "value: " << value 
			<< "\tidx: " << idx 
			<< "\titer: " << __counter << std::endl;

	numbers.insert(numbers.begin() + idx, value);
	printVectorInt("after insertion: ", numbers);
}

int main(void) 
{
	std::cout << "======== Test findIndex ========"  << std::endl;
	int arr[] = {2, 5, 7, 13, 25};
	std::vector<int>	numbers;
	for (size_t i = 0; i < 5; ++i)
		numbers.push_back(arr[i]);
	printVectorInt("before insertion: ", numbers);

	insertValue(numbers, 24);
	insertValue(numbers, 0);
	insertValue(numbers, 26);	
}