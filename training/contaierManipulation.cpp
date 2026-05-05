#include <algorithm>
#include <vector>
#include <iostream>

typedef std::vector<int>::size_type arrsize_t;

void printrange(std::vector<int> arr, arrsize_t begin, arrsize_t end)
{
	std::cout << "( " ; 
	for (; begin < end; ++begin)
		std::cout << arr[begin] << " " ;
	std::cout  << ") " ;
}

void mergesort(arrsize_t round, std::vector<int> & arr ) {
	if (round > arr.size() / 2)
		return ;
	
	for (arrsize_t i = 0; i + 2 * round <= arr.size(); i += 2 * round) {
		if (arr[i + round - 1] > arr[i + 2 * round - 1]) {
			std::swap_ranges(
				arr.begin() + i,
				arr.begin() + i + round,
				arr.begin() + i + round
			);
		}

		printrange(arr, i, i + 2 * round);
	}
	std::cout << std::endl;
	mergesort(round * 2, arr);
}

int main(void) 
{
	int ordered[] = {1,2,3,4,5,6,7,8,9,10, 11,12,13,14,15,16,17,19,19,20,21};
	int unordered[] = {5,2,14,19,20,17,4,12,15,7,13,16,1,8,6,21,3,10,9,18,11};

	std::vector<int> num;
	for (int i = 0; i < 21; ++i )
		num.push_back(unordered[i]);

	std::cout << "vector:\n" ; 
	for (arrsize_t i = 0; i < num.size();  ++i)
		std::cout << num[i] << " ";
	std::cout << "\nfirst: " << num.front() << " last: " << num.back() << std::endl;


	mergesort(1, num);

	std::vector<int> num2;
	for (int i = 0; i < 21; ++i )
		num2.push_back(ordered[i]);
	std::cout << "test" << std::endl;

	printrange(num2, 0, 20);
	std::cout << "\nswap" << std::endl;
	num2 = num;
	printrange(num2, 0, 20);
	// std::swap_ranges(&num[0], &num[5], &num[5]);
	// for (std::vector<int>::size_type i = 0; i < num.size();  ++i)
	// 	std::cout << num[i] << " ";
	// std::cout << "\nfirst: " << num.front() << " last: " << num.back() << std::endl;
}