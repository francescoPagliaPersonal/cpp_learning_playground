#include "header.hpp"

static void statistics(std::vector<int> & arr, idx_id start, idx_id middle, idx_id end)
{
	std::cout << "[" <<  start << "] " << arr[start] ;
	std::cout << "  [" <<  end   << "] " << arr[end]  ;
	std::cout << "  [" <<  middle   << "] " << arr[middle]   << std::endl;
}

idx_id	findIndex(std::vector<int> & arr, int value)
{
	idx_id start = 0;
	idx_id end = arr.size() - 1;
	idx_id middle = (end - start) /2;
	while (end - start != 1)
	{
		if (value > arr[middle])
			start = middle;
		else 
			end = middle;
		middle = start + ((end - start) /2);
		__counter++;
		statistics(arr, start, middle, end);
	}

	if (value > arr[end]) {
		middle = end + 1 ;
		__counter++;
	}
	else {
		middle = value > arr[start] ? start + 1: start;
		__counter++;
	}
	return middle;
}